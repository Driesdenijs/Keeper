#include "door.h"
#include <stdio.h>
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#ifndef UBUNTU
	#include "wiringPi.h"
	#include "piFace.h"
#else
	int emulated_state = 0;
	#define HIGH 1
	#define LOW 0
#endif
// Use 200 as the pin-base for the PiFace board, and pick a pin
//	for the LED that's not connected to a relay

#define	PIFACE	200
#define RELAY   PIFACE
#define MOTOR_A PIFACE
#define MOTOR_B PIFACE+1
#define	LED	(PIFACE+2)
#define DELAY   250

#define OPENCLOSE_THRESHOLD 20

pthread_t t_monDoor;

int outputs [4] = { 0,0,0,0 } ;
const char * const doorStates[] =  {"HOLD","OPENING","CLOSING","IDLE","ERROR"};
volatile int  presumedState = OPENED;
onStateChange onStateChange_cb = NULL;
FILE* message_stream;
//#define OUTPUTSTREAM stdout
#define OUTPUTSTREAM fopen("/dev/null", "w")

void doorPulseOutput(){

#ifndef UBUNTU
  digitalWrite(RELAY,HIGH);
#else
  fprintf(message_stream,"Write port %i to %i\n",RELAY,HIGH);
#endif

  delay(DELAY);

#ifndef UBUNTU
  digitalWrite(RELAY,LOW);
#else
  fprintf(message_stream,"Write port %i to %i\n",RELAY,LOW);
  delay(DELAY);
  emulated_state = (++emulated_state % 4);
  fprintf(message_stream,"emulated_state %i\n",emulated_state);
 #endif
}

int doorGetState(){

	int state; 
	static int prevstate = ERROR;
//	printf("getstate");
#ifndef UBUNTU
   for(int i=0;i<5;i++){
	state = (digitalRead(MOTOR_A) << 1) + digitalRead(MOTOR_B);
        if(state!=prevstate)fprintf(message_stream,".");
        if(prevstate == state)break;
	prevstate = state;
	sleep(1);
   }
#else
   state = emulated_state;
#endif

//   fprintf(message_stream," state = %s\n", states[state]);
   return state;
}

int doorSetState(int state){

  //pulse first measure 
  doorPulseOutput();
  sleep(1);
  for(int i=0; i<4; i++){
     if(doorGetState()!= state){
	doorPulseOutput();
     }else{
	return state;
     }
     sleep(1);
  }
  fprintf(message_stream,"Error in controlling state\n");
  return ERROR;
}

void* monitorDoor(void *arg){

	int position=0, st;
	static int state = IDLE;

        while(1){
	    st = doorGetState();
	    if((st == CLOSING)&& (position > 0))
		position--;
	    else if((st == OPENING) && (position < OPENCLOSE_THRESHOLD))
		position++;
	    else if(position == OPENCLOSE_THRESHOLD)
		presumedState = OPENED;
	    else if(position == 0)
		presumedState = CLOSED;
            usleep(500000);
        }
	if(state != st){
	    if(onStateChange_cb != NULL)
	       onStateChange_cb(st);
	}
}

int doorGetPresumedState(){
	return presumedState;
}

void setOnStateChange_callback(onStateChange cb)
{
   onStateChange_cb = cb;
}

int doorInit(){
  
  int pin,err;
  message_stream = stdout;//OUTPUTSTREAM;

#ifndef UBUNTU
   wiringPiSetupSys ();
   piFaceSetup (PIFACE);

  err = pthread_create(&t_monDoor, NULL, &monitorDoor, NULL);
  if (err != 0)
    printf("\ncan't create thread :[%s]", strerror(err));
  else
    printf("\n Thread created successfully\n");

  // Enable internal pull-ups & start with all off
  for (pin = 0 ; pin < 8 ; ++pin)
  {
    pullUpDnControl (PIFACE + pin, PUD_UP) ;
    digitalWrite    (PIFACE + pin, 0) ;
  }
#else
  fprintf(message_stream,"init wiringPi\n");
#endif

}
