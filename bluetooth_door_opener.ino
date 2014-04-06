#include <Servo.h>
Servo myservo; 
int pin = 13;

const int SENS_PIN = A0;
const int LED_PIN = 13;

int sensorValue = 0;

boolean toggle = true;

void setup() {
  Serial.begin(9600);
  myservo.attach(12);
  pinMode(pin, OUTPUT);
}

void loop() {
  
    myservo.write(0);
      delay(3000);
      myservo.write(180);
     delay(2000);
     int angle = myservo.read();
     Serial.println("Angle is " + angle);
     
     /*
    Serial.println(pin);
  
  
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    */
    /*
    if (Serial.available()) {
        Serial.read();
        sensorValue = analogRead(SENS_PIN);
        Serial.println(sensorValue);
        digitalWrite(LED_PIN, toggle); // toggle the LED
        toggle = !toggle;
    }
    */
    
    
}
     
