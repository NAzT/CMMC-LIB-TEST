#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <PubSubClient.h>
#include <Ticker.h>
#include <CMMC.h>


CMMC cmmc;

int count = 0;

void setup() {
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
}

void loop() {
}
