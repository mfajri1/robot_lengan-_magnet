int r1 = 6;
int l1 = 5;
int pwm1 = 12;

int r2 = 4;
int l2 = 3; 
int pwm2 = 2; 

int pwm = 255;

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(pwm2, OUTPUT);
}
 
void loop() {
     maju();
     delay(3000);
     mundur();
     delay(3000);
     mjkiri();
     delay(3000);
     mjkanan();
     delay(3000);
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
