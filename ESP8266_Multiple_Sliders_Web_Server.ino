/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-web-server-websocket-sliders/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "LittleFS.h"
#include <Arduino_JSON.h>

// Replace with your network credentials****************************
const char* ssid = "Test4x6";
const char* password = "test6666";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
// Create a WebSocket object

AsyncWebSocket ws("/ws");
// Set LED GPIO
const int ledPin1 = 5;
const int ledPin2 = 4;
const int ledPin3 = 0;
const int ledPin4 = 2;
const int ledPin5 = 14;
const int ledPin6 = 12;
const int ledPin7 = 13;
const int ledPin8 = 15; //one of 2 mos
const int ledPin9 = 1; //one of 2 mos, TX pin, need switching function
//as of nodemcu

String message = "";
String sliderValue1 = "0";
String sliderValue2 = "0";
String sliderValue3 = "0";
String sliderValue4 = "0";
String sliderValue5 = "0";
String sliderValue6 = "0";
String sliderValue7 = "0";
String sliderValue8 = "0";
String sliderValue9 = "0";

int dutyCycle1;
int dutyCycle2;
int dutyCycle3;
int dutyCycle4;
int dutyCycle5;
int dutyCycle6;
int dutyCycle7;
int dutyCycle8;
int dutyCycle9;

//Json Variable to Hold Slider Values
JSONVar sliderValues;

//Get Slider Values
String getSliderValues() {
  sliderValues["sliderValue1"] = String(sliderValue1);
  sliderValues["sliderValue2"] = String(sliderValue2);
  sliderValues["sliderValue3"] = String(sliderValue3);
  sliderValues["sliderValue4"] = String(sliderValue4);
  sliderValues["sliderValue5"] = String(sliderValue5);
  sliderValues["sliderValue6"] = String(sliderValue6);
  sliderValues["sliderValue7"] = String(sliderValue7);
  sliderValues["sliderValue8"] = String(sliderValue8);
  sliderValues["sliderValue9"] = String(sliderValue9);


  String jsonString = JSON.stringify(sliderValues);
  return jsonString;
}

// Initialize LittleFS
void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  else {
    Serial.println("LittleFS mounted successfully");
  }
}

// Initialize WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void notifyClients(String sliderValues) {
  ws.textAll(sliderValues);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    message = (char*)data;
    if (message.indexOf("1s") >= 0) {
      sliderValue1 = message.substring(2);
      dutyCycle1 = map(sliderValue1.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle1);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("2s") >= 0) {
      sliderValue2 = message.substring(2);
      dutyCycle2 = map(sliderValue2.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle2);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("3s") >= 0) {
      sliderValue3 = message.substring(2);
      dutyCycle3 = map(sliderValue3.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle3);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("4s") >= 0) {
      sliderValue4 = message.substring(4);
      dutyCycle4 = map(sliderValue4.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle4);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("5s") >= 0) {
      sliderValue5 = message.substring(5);
      dutyCycle5 = map(sliderValue5.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle5);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("6s") >= 0) {
      sliderValue6 = message.substring(6);
      dutyCycle6 = map(sliderValue6.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle6);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("7s") >= 0) {
      sliderValue7 = message.substring(7);
      dutyCycle7 = map(sliderValue7.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle7);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("8s") >= 0) {
      sliderValue8 = message.substring(8);
      dutyCycle8 = map(sliderValue8.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle8);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("9s") >= 0) {
      sliderValue9 = message.substring(9);
      dutyCycle9 = map(sliderValue9.toInt(), 0, 100, 0, 1023);
      Serial.println(dutyCycle9);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }

    //    if (message.indexOf("_replace_s") >= 0) {
    //      sliderValue_replace_ = message.substring(_replace_);
    //      dutyCycle_replace_ = map(sliderValue_replace_.toInt(), 0, 100, 0, 1023);
    //      Serial.println(dutyCycle_replace_);
    //      Serial.print(getSliderValues());
    //      notifyClients(getSliderValues());
    //    }

    if (strcmp((char*)data, "getValues") == 0) {
      notifyClients(getSliderValues());
    }
  }
}
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
//***************************TX WONT WORK NOW _ CODE UNDER CONSTRUCTION
//  pinMode(ledPin9, FUNCTION_3);//GPIO
//  pinMode(ledPin9, OUTPUT);
//  pinMode(ledPin9, FUNCTION_1);//TX
  
  initFS();
  initWiFi();

  initWebSocket();

  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(LittleFS, "/index.html", "text/html");
  });

  server.serveStatic("/", LittleFS, "/");

  // Start server
  server.begin();
}

void loop() {
  analogWrite(ledPin1, dutyCycle1);
  analogWrite(ledPin2, dutyCycle2);
  analogWrite(ledPin3, dutyCycle3);
  analogWrite(ledPin4, dutyCycle4);
  analogWrite(ledPin5, dutyCycle5);
  analogWrite(ledPin6, dutyCycle6);
  analogWrite(ledPin7, dutyCycle7);
  analogWrite(ledPin8, dutyCycle8);
  //analogWrite(ledPin9, dutyCycle9);


  ws.cleanupClients();
}
