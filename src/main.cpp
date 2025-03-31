#include "distance_sensor.h"
#include "motor_controller.h"
#include "step_motor_controller.h"

const int STEPS_IN_FULL_REVOLUTION = 200;

// DistanceSensor* mySensor;
// MotorController actuator(8, 9, 10);

StepMotorController stepper(STEPS_IN_FULL_REVOLUTION, StepMotorController::SteppingMode::FULL, false, 200, 8, 12, 13, 9, 10, 11);

void setup() {
    Serial.begin(9600);
    // mySensor = new DistanceSensor(VL53L1X::Long, 50000, 50, 500, 400000, false);
    delay(1000);
    Serial.println("Starting measurement");
    // Serial.println(mySensor->measure());
}

void loop() {
    stepper.changeStep(StepMotorController::SteppingMode::FULL);
    stepper.stepDegrees(90);
    delay(1000);
    stepper.changeStep(StepMotorController::SteppingMode::HALF);
    stepper.stepDegrees(90);
    delay(1000);
    stepper.changeStep(StepMotorController::SteppingMode::QUARTER);
    stepper.stepDegrees(90);
    delay(1000);
    stepper.changeStep(StepMotorController::SteppingMode::EIGHT);
    stepper.stepDegrees(90);
    delay(1000);
    stepper.changeStep(StepMotorController::SteppingMode::SIXTEENTH);
    stepper.stepDegrees(90);
    delay(1000);

    // delay(1000);
    // delay(50);
    // Serial.println(mySensor->measure());
    // stepper.step(2048);
    // delay(1000); // Wait before repeating
    // stepper.step(-1000);

    // delay(1000);

}
