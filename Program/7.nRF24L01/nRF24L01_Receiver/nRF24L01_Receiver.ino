#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

Servo servo1, servo2, servo3;

RF24 radio(7, 8); // CE, CSN
const byte address = 255;

int ger = 90;
int ger2 = 90;
int ger3 = 90;

int text[8];

int r1 = 9;
int l1 = 10;
int pwm1 = 11;

int r2 = 6;
int l2 = 5; 
int pwm2 = 4; 

int pwm = 255;

int relay = 13;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(12);

  pinMode(r1, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(relay, OUTPUT);

  delay(100);

  radio.begin();
  bool check = radio.isChipConnected();
  Serial.print("check-");
  Serial.println(check);
  
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  
  /*servo1.write(95);
  delay(500);
  servo2.write(95);
  delay(500);
  servo3.write(95);
  delay(500);*/

  digitalWrite(relay, HIGH);
}

void loop() {
  while (radio.available()) {
      
      radio.read(&text, sizeof(text));
      
      /*int i;
      for (i = 0; i < 2; i = i + 1) {
        Serial.print(text[i]);
      }*/
      
      Serial.println();
      Serial.print("X1 = ");
      Serial.println(text[0]);
      Serial.print("X = ");
      Serial.println(text[1]);
      Serial.print("Y = ");
      Serial.println(text[2]);
      Serial.print("Maju = ");
      Serial.println(text[3]);
      Serial.print("Mundur = ");
      Serial.println(text[4]);
      Serial.print("Kiri = ");
      Serial.println(text[5]);
      Serial.print("Kanan = ");
      Serial.println(text[6]);
      Serial.print("Magnet = ");
      Serial.println(text[7]);
      //delay(250);
//////////////SERVO 1//////////////////////////////////////////////////////////////////////
      if(text[0] >= 170){
        ger += 15;
        Serial.println(ger);
        servo1.write(ger);
        if(ger >= 180){
          ger = 180;
        }  
      }

      if(text[0] <= 10){
        ger -= 15;
        Serial.println(ger);
        servo1.write(ger);  
        if(ger <= 10){
          ger = 10;
        }
      }
//////////////SERVO 2//////////////////////////////////////////////////////////////////////
      if(text[1] >= 170){
        ger2 += 15;
        Serial.println(ger2);
        servo2.write(ger2);
        if(ger2 >= 180){
          ger2 = 180;
        }  
      }

      if(text[1] <= 10){
        ger2 -= 15;
        Serial.println(ger2);
        servo2.write(ger2);
        if(ger2 >= 180){
          ger2 = 180;
        }  
      }
//////////////SERVO 3//////////////////////////////////////////////////////////////////////
      if(text[2] >= 170){
        ger3 += 15;
        Serial.println(ger3);
        servo3.write(ger3);  
        if(ger3 <= 10){
          ger3 = 10;
        }
      }

      if(text[2] <= 10){
        ger3 -= 15;
        Serial.println(ger3);
        servo3.write(ger3);  
        if(ger3 <= 10){
          ger3 = 10;
        }
      }
//////////////BUTTON//////////////////////////////////////////////////////////////////////
      if ((text[3] == 0) && (text[5] == 1) && (text[4] == 1) && (text[6] == 1) ) {
        maju();
      }
      else if ((text[3] == 1) && (text[5] == 0) && (text[4] == 1) && (text[6] == 1) ) {
        mundur();
      }
      else if ((text[3] == 1) && (text[5] == 1) && (text[4] == 0) && (text[6] == 1) ) {
        mjkiri();
      }
      else if ((text[3] == 1) && (text[5] == 1) && (text[4] == 1) && (text[6] == 0) ) {
        mjkanan();
      }
      else {
        henti();
      }
//////////////RELAY//////////////////////////////////////////////////////////////////////
      if (text[7] == 0)  {
        digitalWrite(relay, LOW);
      }
      else {
        digitalWrite(relay, HIGH);
      }
      delay(10);
    }
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
