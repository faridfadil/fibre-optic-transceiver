#include "TickSystem.h"
#include "BinaryConverter.h"

String message = "Hello";
String* pointerMessage = &message;

String binaryMessage = "";
String* pointerBinaryMessage = &binaryMessage;

const String INITIALIZING_SIGNAL_BINARY = "111111";
String* pointerInitSignal = &INITIALIZING_SIGNAL_BINARY;

const int TICK_THRESHOLD= 3;
int* pointerTickThreshold = &TICK_THRESHOLD;

const int RECEIVER_DELAY = 1000;
int* pointerReceiverDelay = &RECEIVER_DELAY;

int calibrateDelay = 1000;
int* pointerCalibrateDelay = &calibrateDelay;

byte ledPin = 12;
byte* pointerLedPin = &ledPin;

TickSystem transmitterTickSystem;
BinaryConverter transmitterBinaryConverter(pointerMessage);

void setup() {
  *pointerMessage = "Hello";
  transmitterBinaryConverter.messageToBinary();
  transmitterTickSystem.setTickThreshold(pointerTickThreshold);
  

  pinMode(*pointerLedPin, OUTPUT);
}

void loop() {
  delay(*pointerCalibrateDelay);
  transmitterTickSystem.startTickSystem();
  sendSignalMessage(pointerInitSignal);
  delay(*pointerReiceiverDelay);
  sendSignalMessage(transmitterBinaryConverter.getMessage());
}

void sendSignalMessage(String* pointerInputMessage) {
  
  for(int i = 0; i < *pointerInputMessage.size(); i++){
    if((transmitterTickSystem.getTickCount() % transmitterTickSystem.getTickThreshold()) == 0){
        if(*pointerInputMessage[i] == "0"){
            digitalWrite(*ledPin, HIGH);
          }
        else if(*pointerInputMessage[i] == "1"){
            digitalWrite(*ledPin, LOW);
          }
      }      
  }
    
}
