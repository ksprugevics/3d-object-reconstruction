#include "distance_sensor.h"

DistanceSensor::DistanceSensor(VL53L1X::DistanceMode mode, long measureTimeMicros, int measureIntervalMillis, int timeout, long i2cClockHertz, bool debug) {
    Wire.setClock(i2cClockHertz);
    sensor.setTimeout(timeout);
    if (!sensor.init()) {
        Serial.println("Failed to detect and initialize sensor!");
    }

    sensor.setDistanceMode(mode);
    sensor.setMeasurementTimingBudget(measureTimeMicros);
    sensor.startContinuous(measureIntervalMillis);
    this->debug = debug;
}

int DistanceSensor::measure() {
    sensor.read();
    if (debug) {
        logMeasurement();
    }

    return sensor.ranging_data.range_mm;
}

void DistanceSensor::logMeasurement() {
    Serial.print("Range: ");
    Serial.print(sensor.ranging_data.range_mm);
    Serial.print("\tstatus: ");
    Serial.print(VL53L1X::rangeStatusToString(sensor.ranging_data.range_status));
    Serial.print("\tpeak signal: ");
    Serial.print(sensor.ranging_data.peak_signal_count_rate_MCPS);
    Serial.print("\tambient: ");
    Serial.print(sensor.ranging_data.ambient_count_rate_MCPS);
    Serial.println();
}
