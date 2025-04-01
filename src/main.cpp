#include "distance_sensor.h"
#include "motor_controller.h"
#include "step_motor_controller.h"

const int STEPS_IN_FULL_REVOLUTION = 200;

DistanceSensor* mySensor;
StepMotorController stepper(STEPS_IN_FULL_REVOLUTION, StepMotorController::SteppingMode::HALF, false, 200, 8, 12, 13, 9, 10, 11);

void setup() {
    Serial.begin(9600);
    mySensor = new DistanceSensor(VL53L1X::Long, 70000, 70, 500, 400000, false);
    Serial.println(mySensor->measure());
    Serial.println("Starting measurement");
    delay(5000);
    for (int i = 0; i < STEPS_IN_FULL_REVOLUTION * stepper.getStepMultiplier(); i++) {
        Serial.print(mySensor->measure());
        Serial.print(" ");
        delay(70);
        stepper.step();
    }
    Serial.println("Stopped measuring");
}

void loop() {

}
