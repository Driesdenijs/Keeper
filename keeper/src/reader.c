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

#include <ctype.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <nfc.h>
#include <freefare.h>

#include "config.h"
#include "keyfile.h"
#include "offlineformat.h"
#include "reader.h"


//prototype
FILE* message_stream;
FILE* ndef_stream;
uint8_t *cc_data;
uint8_t *ndef_msg;
uint16_t ndef_msg_len;
keyset keys;
char keyfile[128] = { 0 };
static nfc_device *pnd = NULL;
nfc_target nt;
const nfc_modulation nmModulations[] = {
		{ .nmt = NMT_ISO14443A, .nbr = NBR_106 } };

struct {bool interactive;} read_options = { .interactive = true };

int c, res, flags = 0, error = EXIT_SUCCESS;
nfc_device *device = NULL;
FreefareTag *tags = NULL;
MifareClassicKey default_key = { 0xdc, 0x7b, 0x15, 0xaa, 0x09, 0x38 };

nfc_connstring devices[8];
size_t device_count;
nfc_context *context;

cardcode getCard() {

	cardcode card;
	message_stream = stdout;
	ndef_stream = NULL;
	int res;

	//init interface
	nfc_init(&context);
	if (context == NULL)
		fprintf(message_stream, "Unable to init libnfc (malloc)");


	device_count = nfc_list_devices(context, devices, 8);
	if (device_count <= 0)
		fprintf(message_stream, "No NFC device found\n");

	for (size_t d = 0; d < device_count; d++) {
		device = nfc_open(context, devices[d]);

		if (!device) {
			fprintf(message_stream, "nfc_open() failed\n");
			error = EXIT_FAILURE;
			continue;
		}
			FreefareTag *t = NULL;
		    while((t=freefare_get_tags(device))){
			printf("waiting for a card\n");
		    	if(t[0]==NULL)break;
		    	usleep(100);
		    }
			nfc_initiator_poll_target(device, nmModulations, 1, 0xFF, 1, &nt);
			tags = calloc(5, sizeof(FreefareTag));
			tags[0] = freefare_tag_new(device, nt);

			tags[1] = NULL;

			for (int x = 0; (!error) && tags[x]; x++) {

				if(tags[x]==NULL)break;
				//fprintf(message_stream, "cardtype[%i] = %s\n",x,freefare_get_tag_friendly_name(tags[x]));

				char *tag_uid = freefare_get_tag_uid(tags[x]);
				uint8_t buffer[BUFSIZ];

				fprintf(message_stream, "Found %s with UID %s ",freefare_get_tag_friendly_name(tags[x]), tag_uid);
				//card.cardUID = tag_uid;
				memcpy(card.cardUID,tag_uid,sizeof(card.cardUID));

				int res;
				if ((MIFARE_CLASSIC_1K == freefare_get_tag_type(tags[x]))||(MIFARE_CLASSIC_4K == freefare_get_tag_type(tags[x]))) {
					uint32_t cardID = 0;
					int result = 0, i, value;
					MifareClassicBlock buffer;
					MifareClassicBlockNumber bn;

					if (result = mifare_classic_connect(tags[x]))
						fprintf(message_stream, "MFC connected res %i\n",
								result);
					//else
					//	printf("Card connected\n");

					if (result = mifare_classic_authenticate(tags[x], 4,
							default_key, MFC_KEY_A)) {
						//fprintf (message_stream, "Authenticate res %i\n",result);
					}
					if (result = mifare_classic_read(tags[x], 4, &buffer)) {
						//fprintf (message_stream,"read result %i\n", result);
					}
					if (!result) {

						cardID += buffer[12];
						cardID <<= 8;
						cardID += buffer[13];
						cardID <<= 8;
						cardID += buffer[14];
						cardID <<= 8;
						cardID += buffer[15];
						card.cardnumber = cardID;
						fprintf(message_stream, "-%08i\n", cardID);
					} else {
						fprintf(message_stream, "\n");
					}
					//while (0 == nfc_initiator_target_is_present(device, NULL))						;
					mifare_classic_disconnect(tags[x]);
					//printf("disconnect\n");
				}

				if (tags[x] != NULL) {
					//printf("free tag[%i]\n",x);
					free(tags[x]);
					tags[x] = NULL;
				}
			}			//for loop

			if (tags != NULL) {
				//printf("free tags\n");
				free(tags);
				tags = NULL;
			}
		//}			//while loop
		nfc_close(device);
		nfc_exit(context);
	}			//device for loop
	return card;

}			//main

