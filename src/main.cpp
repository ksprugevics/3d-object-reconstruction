#include "distance_sensor.h"
#include "motor_controller.h"

DistanceSensor* mySensor;
MotorController platform(6, 7, 5);

void setup() {
    Serial.begin(9600);
    // mySensor = new DistanceSensor(VL53L1X::Long, 50000, 50, 500, 400000, false);
}

void loop() {
    // Serial.println(mySensor->measure());
    platform.spinClockwise();
}
