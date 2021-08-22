#include <LiquidCrystal.h>
#include "TickSystem.h"
#include "BinaryConverter.h"

String receivedMessageBinary = "";
String* pointerReceivedMessageBinary = &receivedMessageBinary;

// code section start: SHOULD BE THE SAME FOR BOTH TRANSMITTER AND RECEIVER ------

const String INITIALIZING_SIGNAL_BINARY = "111111";
String* pointerInitSignal = &INITIALIZING_SIGNAL_BINARY;

const String TERMINATE_SIGNAL_BINARY = "000000";
String* pointerTerminateSignal = &TERMINATE_SIGNAL_BINARY;

const int TICK_THRESHOLD= 3;
int* pointerTickThreshold = &TICK_THRESHOLD;

const int RECEIVER_DELAY = 1000;
int* pointerReceiverDelay = &RECEIVER_DELAY;

// code section end: SHOULD BE THE SAME FOR BOTH TRANSMITTER AND RECEIVER ------

const int LIGHT_THRESHOLD = 200;
int* pointerLightThreshold = &LIGHT_THRESHOLD;

int analogSignal;
int* pointerAnalogSignal = &analogSignal;

int photoDiodePin = A5;
int* pointerPhotoDiodePin = &photoDiodePin;

bool initialized = false;

enum LCD_PIN{
    RS,
    E,
    DB4,
    DB5,
    DB6,
    DB7
  }
byte[] lcdPin = {12, 11, 4, 5, 6, 7};

LiquidCrystal lcd(lcdPin[LCD_PIN.RS], lcdPin[LCD_PIN.E], lcdPin[LCD_PIN.DB4],lcdPin[LCD_PIN.DB5], lcdPin[LCD_PIN.DB6], lcdPin[LCD_PIN.DB7]);

TickSystem receiverTickSystem;
BinaryConverter receiverBinaryConverter;

void setup() {
  for(int i = 0; i < lcdPin.length(); i++){
      pinMode(*(&lcdPin + i), OUTPUT);
    }
  receiverTickSystem.setTickThreshold(pointerTickThreshold);
  pinMode(*pointerPhotoDiodePin, INPUT);

}

void loop() {
  if(!initialized){
    receiverTickSystem().startTickSystem();
    *pointerAnalogSignal = analogRead(*pointerPhotoDiodePin);
    stringAppendProcess();
        
    if(*pointerReceivedMessageBinary == *pointerInitSignal){
        initialized = true;      
    }
  }else{
    receiverTickSystem.resetTickCount();
    delay(*pointerReceiverDelay);
    stringAppendProcess();
    if(*pointerReceivedMessageBinary == *pointerTerminateSignal){
        messageLcdDisplayProcess();
      }
  }

}

void stringAppendProcess(){
  if(*pointerAnalogSignal > *pointerLightThreshold){    
    *pointerReceivedMessageBinary.append(1);      
  }else{      
    *pointerReceivedMessageBinary.append(0);      
    }
}

void messageLcdDisplayProcess(){
    receiverBinaryConverter.binaryToMessage(*pointerReceivedMessageBinary);
    lcd.print(receiverBinaryConverter.getFinalMessage());
  }
