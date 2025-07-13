#include "DCMotor.h"

DCMotor::DCMotor(
  unsigned short int aPin,
  unsigned short int bPin,
  unsigned short int pwmPin) {
  this->aPin = aPin;
  this->bPin = bPin;
  this->pwmPin = pwmPin;
}

DCMotor *DCMotor::setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  return this;
};

DCMotor *DCMotor::move(short int speed) {
  if (speed >=0) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, LOW);
  } else if (speed < 0) {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, HIGH);
  }
  analogWrite(pwmPin, abs(speed));
  return this;
};

void DCMotor::stop() {
  move(0);
};