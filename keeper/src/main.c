/*-
 * Copyright (C) 2010, Audrey Diacre.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "door.h"
#include "reader.h"

//Sockets
int listenfd = 0, connfd = 0;
struct sockaddr_in serv_addr; 
char sendBuff[1025];
time_t ticks;
pthread_t t_socket;;


#define NELT(a) (sizeof(a)/sizeof(a[0]))
const char * const validCards[] =  {
	"12345678",// #6
};


int currentState = CLOSED;
cardcode cc;

int initSockets(int soc){

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(soc); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 1); 

}

bool checkRights(cardcode card)
{
	int i;
	for(i=0; i < NELT(validCards) ; i++){
		if(strcmp(validCards[i],card.cardUID)==0)
			return true;
	}
    return false;
}

void* socketListener(void *arg){
    
    char cmd[10];    
    int n,i;

    while(1){
      while( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) > 0){
        n=read(connfd,sendBuff,100);
	printf("> %s\n",sendBuff);
	ticks = time(NULL);
        if(!strncmp(sendBuff,"close",5) ){
            doorSetState(CLOSING);
            snprintf(sendBuff, sizeof(sendBuff), "Close @ %.24s\r\n", ctime(&ticks));
	    write(connfd, sendBuff, strlen(sendBuff));
	    printf("closed by socket\n");
        }else if(!strncmp(sendBuff,"open",4)){
            doorSetState(OPENING);
	    snprintf(sendBuff, sizeof(sendBuff), "Open @ %.24s\r\n", ctime(&ticks));
	    write(connfd, sendBuff, strlen(sendBuff));
	    printf("Opened by socket\n");
        }else{
	    snprintf(sendBuff, sizeof(sendBuff), "Failed @ %.24s\r\n", ctime(&ticks));
	    write(connfd, sendBuff, strlen(sendBuff));
	    printf("no match\n");
	    sprintf(cmd,"Failed");
	} 

        close(connfd);
        sleep(1);
      } 
   }
}

int main(int argc, char *argv[]){

	int i,err;

	doorInit();
	initSockets(5000);

        printf("start closing...\n");
	//doorSetState(CLOSING);
	printf("done closing...\n");
    
	err = pthread_create(&t_socket, NULL, &socketListener, NULL);
  	if (err != 0)
    		printf("\ncan't create socket thread :[%s]", strerror(err));
  	else
    		printf("\n Thread created socket successfully\n");

	while(1){

		//blocking getcard function
		cc = getCard();
		printf("card %s %i\n",cc.cardUID,cc.cardnumber);
		if(checkRights(cc))
		{
			printf("card is valid");
			if(doorGetPresumedState() == OPENED){
				doorSetState(CLOSING);
				currentState = CLOSED;
			}else{
				doorSetState(OPENING);
				currentState = OPENED;
			}
		}

	}
}

