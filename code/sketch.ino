#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
Servo myServo;

const int minDist = 2;   // cm - khoảng cách gần nhất
const int maxDist = 30;  // cm - khoảng cách xa nhất

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(6);
  Serial.begin(9600);
}

long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms
  long distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  long distance = readDistance();
  distance = constrain(distance, minDist, maxDist);

  int angle = map(distance, minDist, maxDist, 0, 180);
  myServo.write(angle);

  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.print(" cm -> Goc: ");
  Serial.println(angle);

  delay(100);
}


