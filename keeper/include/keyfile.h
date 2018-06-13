/*
 * keyfile.h
 *
 *  Created on: Jan 5, 2018
 *      Author: dries
 */

#ifndef INCLUDE_KEYFILE_H_
#define INCLUDE_KEYFILE_H_

typedef unsigned char key[16];

typedef key keyset[11];  //key0...key9 + kpkey

enum {
	KEY_0 = 0,
	KEY_R_1,
	KEY_W_1,
	KEY_RW_1,
	KEY_R_2,
	KEY_W_2,
	KEY_RW_2,
	KEY_R_3,
	KEY_W_3,
	KEY_RW_3,
	KP_KEY,
};

int decodeKeyFile(char* , keyset  );

#endif /* INCLUDE_KEYFILE_H_ */
