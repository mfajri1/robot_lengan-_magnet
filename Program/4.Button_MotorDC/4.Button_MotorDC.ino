int button1 = 22, button2 = 23, button3 = 24, button4 = 25;

int nilaibt1, nilaibt2, nilaibt3, nilaibt4;

int r1 = 9;
int l1 = 10;
int pwm1 = 11;

int r2 = 6;
int l2 = 5; 
int pwm2 = 4; 

int pwm = 255;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  pinMode(r1, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  tombol();

  /*nilaibt1 = digitalRead(button1);
  nilaibt2 = digitalRead(button2);
  nilaibt3 = digitalRead(button3);
  nilaibt4 = digitalRead(button4);

  String ap = String (nilaibt1) + "|" + String (nilaibt2) + "|" + String (nilaibt3) + "|" + String (nilaibt4);
  
  Serial.println(ap);*/

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

  /*if ((nilaibt1 == 0) && (nilaibt2 == 1) && (nilaibt3 == 1) && (nilaibt4 == 1) ) {
    maju();
  }
  else if ((nilaibt1 == 1) && (nilaibt2 == 0) && (nilaibt3 == 1) && (nilaibt4 == 1) ) {
    mundur();
  }
  else if ((nilaibt1 == 1) && (nilaibt2 == 1) && (nilaibt3 == 0) && (nilaibt4 == 1) ) {
    mjkiri();
  }
  else if ((nilaibt1 == 1) && (nilaibt2 == 1) && (nilaibt3 == 1) && (nilaibt4 == 0) ) {
    mjkanan();
  }
  else {
    henti();
  }*/
}

void tombol() {
  nilaibt1 = digitalRead(button1);
  nilaibt2 = digitalRead(button2);
  nilaibt3 = digitalRead(button3);
  nilaibt4 = digitalRead(button4);
  
  String ap = String (nilaibt1) + "|" + String (nilaibt2) + "|" + String (nilaibt3) + "|" + String (nilaibt4);
  
  /*Serial.println(nilaibt1);
  Serial.println(nilaibt2);
  Serial.println(nilaibt3);
  Serial.println(nilaibt4);
  delay(500);*/

  Serial.println(ap);
  
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
