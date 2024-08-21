#include "WaterTempMeasurer.hpp"
#include <ArduinoECCX08.h>

WaterTempMeasurer::WaterTempMeasurer(Sensor_IF* s_i, DataBuffer* d){
    sensor = s_i;
    databuffer = d;
}
int WaterTempMeasurer::measure(){
    Serial.println("WaterTempMeasurer.measure() called");
    struct Record record;
    record.time_msec = millis();
    record.temperature = sensor->read_data();

    databuffer->append(record);
    return 0;
}