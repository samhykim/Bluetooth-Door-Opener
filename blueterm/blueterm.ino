#include <SoftwareSerial.h>// import the serial library

SoftwareSerial bluetooth(10, 11); // RX, TX

int ledPin = 13;  // use the built in LED on pin 13 of the Uno
int state = 0;
int flag = 0;        // make sure that you return the state only once
 
void setup() {
    // sets the pins as outputs:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
 
    Serial.begin(9600); // Default connection rate for my BT module
    bluetooth.begin(9600);
}
 
void loop() {
    //if some data is sent, read it and save it in the state variable
    if(bluetooth.available() > 0){
      state = bluetooth.read();
      bluetooth.println(state, DEC);
      flag=0;
    }
    // if the state is 0 the led will turn off
    if (state == '0') {
        digitalWrite(ledPin, LOW);
        if(flag == 0){
          bluetooth.println("LED: off");
          flag = 1;
        }
    }
    // if the state is 1 the led will turn on
    else if (state == '1') {
        digitalWrite(ledPin, HIGH);
        if(flag == 0){
          bluetooth.println("LED: on");
          flag = 1;
        }
    }
}
