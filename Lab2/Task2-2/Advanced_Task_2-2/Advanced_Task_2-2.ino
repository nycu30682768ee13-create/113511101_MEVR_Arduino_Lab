#include <Servo.h>

const int trigPin = 6;
const int echoPin = 7; 
const int servoPin = 9;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  //音速每微秒0.034cm
  int safeDistance = constrain(distance, 2, 30); //限制感測距離範圍，避免讀取誤差造成亂轉
  int angle = map(safeDistance, 2, 30, 0, 180);
  myServo.write(angle);
  delay(30);
}
