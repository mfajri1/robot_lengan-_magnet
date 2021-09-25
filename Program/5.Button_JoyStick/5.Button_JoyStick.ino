int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;

int x = A0, y = A1, x1 = A2;
int nilaiX, nilaiY, nilaiX1;

int nilaibt1, nilaibt2, nilaibt3, nilaibt4;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  
  pinMode(x1, INPUT_PULLUP);
  pinMode(x, INPUT_PULLUP);
  pinMode(y, INPUT_PULLUP);
}

void loop() {
  nilaibt1 = digitalRead(button1);
  nilaibt2 = digitalRead(button2);
  nilaibt3 = digitalRead(button3);
  nilaibt4 = digitalRead(button4);

  nilaiX1 = map(analogRead(x1),0,1023,0,180);
  nilaiX = map(analogRead(x),0,1023,0,180);
  nilaiY = map(analogRead(y),0,1023,0,180);

String bt = String (nilaibt1) + "|" + String (nilaibt2) + "|" + String (nilaibt3) + "|" + String (nilaibt4);
String js = String (nilaiX1) + "|" + String (nilaiX) + "|" + String (nilaiY);
  
  Serial.println(bt);
  Serial.println(js);
  delay(500);
}
