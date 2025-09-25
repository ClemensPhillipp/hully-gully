#include <Servo.h>

Servo servo;

int GSM1 = 10;
int GSM2 = 11;

// ******Parameter******
int maxspeed = 255;
int spinning_time = 1000;
int pause_time = 5000;
// ******Parameter******

#define In1 5
#define In2 6

#define In3 7
#define In4 8

int minPos = 180;
int pos = minPos;
int maxPos = 120;

void setup() {
  servo.attach(9);
  servo.write(pos);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);

  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(GSM2, OUTPUT);
}

void loop() {
  startSpin();
  rotate();
  delay(spinning_time);
  
  //stopSpin();
  reverseSpin();
  delay(spinning_time);
  up();
  //stopRotate();
  reverseRotate();

  delay(spinning_time);
  
  delay(spinning_time);
  down();
  stopSpin();
  stopRotate();
  delay(pause_time);
}

void up() {
  for (pos; pos >= maxPos; pos -= 1) {
    servo.write(pos);
    delay(15);
  }
}

void down() {
  for (pos; pos <= minPos; pos += 1) {
    servo.write(pos);
    delay(15);
  }
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM1, i);
    delay(10);
  }
}

void reverseSpin() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM1, i);
    delay(10);
  }
}

void rotate() {
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM2, i);
    delay(10);
  }
}

void reverseRotate() {
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM2, i);
    delay(10);
  }
}


void stopRotate() {
  for (int i = maxspeed; i >= 0; i -= 1) {
    analogWrite(GSM2, i);
    delay(10);
  }
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void stopSpin() {
  for (int i = maxspeed; i >= 0; i -= 1) {
    analogWrite(GSM1, i);
    delay(10);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}
