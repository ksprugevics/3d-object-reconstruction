#ifndef STEP_MOTOR_CONTROLLER_H
#define STEP_MOTOR_CONTROLLER_H

#include <Arduino.h>

class StepMotorController {
    public:
    enum class SteppingMode {FULL, HALF, QUARTER, EIGHT, SIXTEENTH};
    StepMotorController(int steps, SteppingMode steppingMode, bool directionClockwise, int stepDelayMicros, int enablePin, int stepPin, int directionPin, int ms1Pin, int ms2Pin, int ms3Pin);
        void enable();
        void disable();
        void changeDirectionToClockwise();
        void changeDirectionToCounterClockwise();
        void changeStep(SteppingMode steppingMode);
        void changeStepToFull();
        void changeStepToHalf();
        void changeStepToQuarter();
        void changeStepToEight();
        void changeStepToSixteenth();
        void step();
        void step(int count);
        void fullRotation();
        int getStepMultiplier();
        void stepDegrees(int degree);
    private:
        int steps;
        SteppingMode steppingMode;
        int stepDelayMicros;
        int enablePin;
        int stepPin;
        int directionPin;
        int ms1Pin;
        int ms2Pin;
        int ms3Pin;
};

#endif
