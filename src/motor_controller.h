#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_h

#include <Arduino.h>

class MotorController {
    public:
        MotorController(int pin1, int pin2, int pinPwm);
        void stop();
        void spinClockwise();
        void spinClockwise(int speed);
        void spinCounterClockwise();
        void spinCounterClockwise(int speed);

    private:
        static const int MAX_PWM = 255;
        int pin1;
        int pin2;
        int pinPwm;
};

#endif
