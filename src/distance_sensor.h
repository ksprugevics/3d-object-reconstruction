#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <Arduino.h>
#include <VL53L1X.h>
#include <Wire.h>

class DistanceSensor {
    public:
        DistanceSensor(VL53L1X::DistanceMode, long measureTimeMicros, int measureIntervalMillis, int timeout, long i2cClockHertz, bool debug);
        int measure();
        void logMeasurement();

    private:
        VL53L1X sensor;
        bool debug;
};

#endif
