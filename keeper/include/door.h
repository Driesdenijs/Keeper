/*
 * door.h
 *
 *  Created on: Feb 27, 2018
 *      Author: dries
 */

#ifndef INCLUDE_DOOR_H_
#define INCLUDE_DOOR_H_

//#define UBUNTU

enum DOOR_STATE{
  HOLD=0,
  OPENING,
  CLOSING,
  IDLE,
  ERROR
};

enum PRESUMED_STATE{
    OPENED,
    CLOSED
};

extern const char * const doorStates[];

typedef void(*onStateChange)(int);

void setOnStateChange_callback(void(*onStateChange)(int));
int doorInit();
void doorPulseOutput();
int doorGetState();
int doorSetState(int state);
int doorGetPresumedState();
#endif /* INCLUDE_DOOR_H_ */
