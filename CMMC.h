/* 
  CMMC.h - esp8266 library that calls functions periodically

  Copyright (c) 2014 Ivan Grokhotkov. All rights reserved.
  This file is part of the esp8266 core for Arduino environment.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/



#ifndef CMMC_H
#define CMMC_H

#include "ESP8266WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "PubSubClient.h"
#include "Ticker.h"


#define WIFI_MAX_RETRIES 150
#define WIFI_CONNECT_DELAY_MS 1000

#define DEBUG_MODE


#define DEBUG_PRINTER Serial

#ifdef DEBUG_MODE
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTLN(...) {}
#endif

#ifndef DEBUG_MODE
#define PRODUCTION_MODE
#endif

#define CLIENT_ID_PREFIX "esp8266-"
#define DEVICE_NAME "NAT"


#define STATE_WIFI_CONNECTING    0
#define STATE_WIFI_CONNECTED     1

#define STATE_MQTT_CONNECTING    2
#define STATE_MQTT_CONNECTED     3
#define STATE_MQTT_SUBSCRIBING   4
#define STATE_MQTT_SUBSCRIBED    5

#define STATE_READY_TO_GO        6

//-------
#define STATE_GOT_CLIENT_ID      7
#define STATE_RESET              8
//-------

#define LED_PIN 1 // <<<==== 1 = TX0 PIN 



class CMMC
{
public:
	CMMC();
	~CMMC();
	typedef void (*callback_t)(void);
	typedef void (*callback_with_arg_t)(void*);

	void detach();
  char* getClientId();
  void callback(const MQTT::Publish& pub);



protected:
  Ticker publisher;

  char* clientId;
  char* clientTopic;

unsigned long prevMillisPub = 0;
};


#endif//CMMC_H
