#include "motor_controller.h"

MotorController::MotorController(int pin1, int pin2, int pinPwm) {
    this->pin1 = pin1;
    this->pin2 = pin2;
    this->pinPwm = pinPwm;

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pinPwm, OUTPUT);

    stop();
}

void MotorController::stop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void MotorController::spinClockwise() {
    spinClockwise(MAX_PWM);
}

void MotorController::spinClockwise(int speed) {
    speed = constrain(speed, 0, MAX_PWM);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    analogWrite(pinPwm, speed);
}

void MotorController::spinCounterClockwise() {
    spinCounterClockwise(MAX_PWM);
}

void MotorController::spinCounterClockwise(int speed) {
    speed = constrain(speed, 0, MAX_PWM);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    analogWrite(pinPwm, speed);
}
