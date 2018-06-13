/*
 * reader.h
 *
 *  Created on: Feb 27, 2018
 *      Author: dries
 */

#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_


typedef struct {
	char cardUID[32];
	int cardnumber;
}cardcode;

cardcode getCard();


#endif /* INCLUDE_READER_H_ */
