#include "WaterTempSensor.hpp"
#include <ArduinoECCX08.h>

WaterTempSensor::WaterTempSensor(ADConverter* a){
    adc = a;
    init();
}

int WaterTempSensor::init(){
    Serial.println("WaterTempSensor.init() called");
    return 0;
}
double WaterTempSensor::read_data(){
    Serial.println("WaterTempSensor.read_data() called");
    unsigned int advalue;
    advalue = adc->get_Data();
    return (double)advalue;
}