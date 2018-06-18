/*
 * reader.h
 *
 *  Created on: Feb 27, 2018
 *      Author: dries
 */

#ifndef INCLUDE_MQTT_H_
#define INCLUDE_MQTT_H_

int (*on_message)(void *context, char *topicName, int topicLen, MQTTClient_message *message);

int initMqtt(MQTTClient client , int (*on_message)(void *context, char *topicName, int topicLen, MQTTClient_message *message));
void publish(MQTTClient client, char* topic, char* payload);


#endif /* INCLUDE_READER_H_ */
