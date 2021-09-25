#include <Servo.h>

Servo myservo; 

int pos = 95;  

void setup() {
  myservo.attach(2); 
  myservo.write(pos);
  delay(2000);
}

void loop() {
  /*for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(10);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);            
    delay(10);                      
  }
  delay(500);*/
}
