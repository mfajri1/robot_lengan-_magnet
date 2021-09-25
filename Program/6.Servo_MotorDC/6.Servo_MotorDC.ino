#include <Servo.h>

Servo servo1, servo2, servo3;

int r1 = 9;
int l1 = 10;
int pwm1 = 11;

int r2 = 6;
int l2 = 5; 
int pwm2 = 4; 

int pwm = 255;

int pos = 95; 

void setup() {
  Serial.begin(9600);
  
  pinMode(r1, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(12);

  servo1.write(pos);
  servo2.write(pos);
  servo3.write(pos);
}

void loop() {
  ms1();
  delay(4000);
  
  ms2();
  delay(4000);
  
  ms3();
  delay(4000);
  
  maju();
  delay(2000);
  mundur();
  delay(2000);
  mjkanan();
  delay(2000);
  mjkiri();
  delay(2000);
  henti();
  delay(2000);
  
}

void ms1() {
  for (pos = 0; pos <= 180; pos += 1) { 
    servo1.write(pos);              
    delay(10);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo1.write(pos);            
    delay(10);                     
  }
  delay(500);
  servo1.write(95);
  delay(500); 
}

void ms2() {
  for (pos = 0; pos <= 180; pos += 1) { 
    servo2.write(pos);              
    delay(10);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo2.write(pos);            
    delay(10);                      
  }
  delay(500);
  servo2.write(95);
  delay(500); 
}

void ms3() {
  for (pos = 0; pos <= 180; pos += 1) { 
    servo3.write(pos);              
    delay(10);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo3.write(pos);            
    delay(10);                      
  }
  delay(500);
  servo3.write(95);
  delay(500); 
}

void maju() {
  analogWrite(pwm1, pwm);
  digitalWrite(r1, HIGH);
  digitalWrite(l1, LOW);
  analogWrite(pwm2, pwm);
  digitalWrite(r2, HIGH);
  digitalWrite(l2, LOW);
}

void mundur() {
  analogWrite(pwm1, pwm);
  digitalWrite(r1, LOW);
  digitalWrite(l1, HIGH);
  analogWrite(pwm2, pwm);
  digitalWrite(r2, LOW);
  digitalWrite(l2, HIGH);
}

void mjkiri() {
  analogWrite(pwm1, pwm);
  digitalWrite(r1, LOW);
  digitalWrite(l1, LOW);
  analogWrite(pwm2, pwm);
  digitalWrite(r2, HIGH);
  digitalWrite(l2, LOW);
}

void mjkanan() {
  analogWrite(pwm1, pwm);
  digitalWrite(r1, HIGH);
  digitalWrite(l1, LOW);
  analogWrite(pwm2, pwm);
  digitalWrite(r2, LOW);
  digitalWrite(l2, LOW);
}

void henti() {
  digitalWrite(pwm1, 0);
  digitalWrite(pwm2, 0);
}
