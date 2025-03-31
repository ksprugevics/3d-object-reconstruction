#include "step_motor_controller.h"

StepMotorController::StepMotorController(int steps, SteppingMode steppingMode, bool directionClockwise, int stepDelayMicros, int enablePin, int stepPin, int directionPin, int ms1Pin, int ms2Pin, int ms3Pin) {
    this->steps = steps;
    this->steppingMode = steppingMode;
    this->stepDelayMicros = stepDelayMicros;
    this->enablePin = enablePin;
    this->stepPin = stepPin;
    this->directionPin = directionPin;
    this->ms1Pin = ms1Pin;
    this->ms2Pin = ms2Pin;
    this->ms3Pin = ms3Pin;

    pinMode(enablePin, OUTPUT);  
    pinMode(stepPin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(ms1Pin, OUTPUT);
    pinMode(ms2Pin, OUTPUT);
    pinMode(ms3Pin, OUTPUT);

    digitalWrite(stepPin, LOW);
    if (directionClockwise) {
        changeDirectionToClockwise();
    } else {
        changeDirectionToCounterClockwise();
    }
    enable();
    changeStep(steppingMode);
}

void StepMotorController::enable() {
    digitalWrite(enablePin, LOW);
}

void StepMotorController::disable() {
    digitalWrite(enablePin, HIGH);
}

void StepMotorController::changeDirectionToClockwise() {
    digitalWrite(directionPin, LOW);
}

void StepMotorController::changeDirectionToCounterClockwise() {
    digitalWrite(directionPin, HIGH);
}

void StepMotorController::changeStep(SteppingMode steppingMode) {
    this->steppingMode = steppingMode;
    switch (steppingMode) {
        case SteppingMode::FULL: changeStepToFull(); break;
        case SteppingMode::HALF: changeStepToHalf(); break;
        case SteppingMode::QUARTER: changeStepToQuarter(); break;
        case SteppingMode::EIGHT: changeStepToEight(); break;
        case SteppingMode::SIXTEENTH: changeStepToSixteenth(); break;
    }
}

void StepMotorController::changeStepToFull() {
    digitalWrite(ms1Pin, LOW);
    digitalWrite(ms2Pin, LOW);
    digitalWrite(ms3Pin, LOW);
}

void StepMotorController::changeStepToHalf() {
    digitalWrite(ms1Pin, HIGH);
    digitalWrite(ms2Pin, LOW);
    digitalWrite(ms3Pin, LOW);
}

void StepMotorController::changeStepToQuarter() {
    digitalWrite(ms1Pin, LOW);
    digitalWrite(ms2Pin, HIGH);
    digitalWrite(ms3Pin, LOW);
}

void StepMotorController::changeStepToEight() {
    digitalWrite(ms1Pin, HIGH);
    digitalWrite(ms2Pin, HIGH);
    digitalWrite(ms3Pin, LOW);
}

void StepMotorController::changeStepToSixteenth() {
    digitalWrite(ms1Pin, HIGH);
    digitalWrite(ms2Pin, HIGH);
    digitalWrite(ms3Pin, HIGH);
}

void StepMotorController::step() {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelayMicros);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelayMicros);
}

void StepMotorController::step(int count) {
    for (int i = 0; i < count; i++) {
        step();
    }
}

void StepMotorController::fullRotation() {
    int stepMultiplier = getStepMultiplier();
    for (int i = 0; i < steps * stepMultiplier; i++) {
        step();
    }
}

int StepMotorController::getStepMultiplier() {
    switch (steppingMode) {
        case SteppingMode::FULL: return 1; break;
        case SteppingMode::HALF: return 2; break;
        case SteppingMode::QUARTER: return 4; break;
        case SteppingMode::EIGHT: return 8; break;
        case SteppingMode::SIXTEENTH: return 16; break;
    }
}

void StepMotorController::stepDegrees(int degree) {
    degree = degree % 360;
    int stepsOneDegree = getStepMultiplier() * steps / 360;
    int steps = stepsOneDegree * degree;

    for (int i = 0; i < steps; i++) {
        step();
    }
}
