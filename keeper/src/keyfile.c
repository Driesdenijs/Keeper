#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "keyfile.h"

#define MAX_LINES 20
#define AES_KEY_SIZE 16 //16byte keys



int decodeKeyFile(char* file, keyset keys )
{
    FILE *fptr;
    if ((fptr = fopen(file, "r")) == NULL)
    {
        // Program exits if file pointer returns NULL.
        return -1;
    }

	char buffer[100];
    char * result;
    int val,succesfull_keys=0;
    int length = 0;
    // reads text until newline
    for(int i = 0 ; i < MAX_LINES; i++){
    	//get line from file
    	if(fgets(buffer, 100 , fptr) != NULL){
    		length = strlen(buffer);
    		//first check is the string length is valid
    		if(length < ((AES_KEY_SIZE*2)+1)){
    			 printf("keysize not valid: %s\n", buffer);
    		}else{
    			succesfull_keys++;
    			for(int j=0 ; j< AES_KEY_SIZE ; j++){
    				if(sscanf(&buffer[j*2],"%02x",&val) != 1 ){
    					succesfull_keys--;
    					printf("key failed %s\n",buffer);
    					break;
    				}else{
    					//put key byte in array, regardless of the total key will succeed
    					keys[i][j] = (unsigned char)val;
    				}
       			}
    		}
    	}
    }

    fclose(fptr);

    return succesfull_keys;

}

