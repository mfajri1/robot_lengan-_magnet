#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address = 255;

int message[8];

int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;

int lmswitch = 6;

int x = A0, y = A1, x1 = A2;
int nilaiX, nilaiY, nilaiX1;

int nilaibt1, nilaibt2, nilaibt3, nilaibt4;

void setup() {
  Serial.begin(9600);
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  
  pinMode(lmswitch, INPUT_PULLUP);
  
  pinMode(x1, INPUT_PULLUP);
  pinMode(x, INPUT_PULLUP);
  pinMode(y, INPUT_PULLUP);
  
  radio.begin();
  bool check = radio.isChipConnected();
  Serial.print("check-");
  Serial.println(check);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}
void loop() {
  nilaibt1 = digitalRead(button1);
  nilaibt2 = digitalRead(button2);
  nilaibt3 = digitalRead(button3);
  nilaibt4 = digitalRead(button4);

  nilailms = digitalRead(lmswitch);

  nilaiX1 = map(analogRead(x1),0,1023,0,180);
  nilaiX = map(analogRead(x),0,1023,0,180);
  nilaiY = map(analogRead(y),0,1023,0,180);

  message[0] = nilaiX1;
  message[1] = nilaiX;
  message[2] = nilaiY;
  message[3] = nilaibt1; 
  message[4] = nilaibt2; 
  message[5] = nilaibt3; 
  message[6] = nilaibt4;  

  Serial.println("Kirim");
  radio.write(&message, sizeof(message));
  Serial.print("X1 = ");
  Serial.println(message[0]);
  Serial.print("X = ");
  Serial.println(message[1]);
  Serial.print("Y = ");
  Serial.println(message[2]);
  Serial.print("BT1 = ");
  Serial.println(message[3]);
  Serial.print("BT2 = ");
  Serial.println(message[4]);
  Serial.print("BT3 = ");
  Serial.println(message[5]);
  Serial.print("BT4 = ");
  Serial.println(message[6]);
  Serial.print("Switch = ");
  Serial.println(message[7]);
  delay(10);
}
