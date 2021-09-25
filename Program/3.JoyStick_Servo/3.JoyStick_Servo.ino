#include<Servo.h>

Servo servo0, servo1, servo2;

int x = A0, y = A1, x1 = A2;

int nilaiX, nilaiY, nilaiX1;

void setup() {
 Serial.begin(9600);
 servo0.attach(2);
 servo1.attach(3);
 servo2.attach(4);

 pinMode(x1, INPUT_PULLUP);
 pinMode(x, INPUT_PULLUP);
 pinMode(y, INPUT_PULLUP);

 servo0.write(0);
 servo1.write(0);
 servo2.write(0);
}

void loop() {
  nilaiX1 = map(analogRead(x1),0,1023,0,180);
  nilaiX = map(analogRead(x),0,1023,0,180);
  nilaiY = map(analogRead(y),0,1023,0,180);

  servo0.write(nilaiX1);
  servo1.write(nilaiX);
  servo2.write(nilaiY); 
}
