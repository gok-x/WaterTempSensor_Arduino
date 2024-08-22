#include "WaterTempSensor.hpp"
#include <ArduinoECCX08.h>

WaterTempSensor::WaterTempSensor(ADConverter* a, unsigned int rR){
    adc = a;
    refResistance = rR;
    init();
}

int WaterTempSensor::init(){
    //Serial.println("WaterTempSensor.init() called");
    return 0;
}
double WaterTempSensor::read_data(){
    //Serial.println("WaterTempSensor.read_data() called");
    int advalue_means = 0;
    for(int i = 0; i < NUMSHOTS; i++)
        advalue_means += adc->get_Data();
    advalue_means /= NUMSHOTS;
    return calc_temperature(advalue_means);
}
double WaterTempSensor::calc_temperature(int advalue){
    //temperature = 1.0 / (temp1 + temp2) - ABSTEMP
    double restistance, temp1, temp2, temperature;
    restistance = (double)(((1 << adc->get_resolution()) - 1) - advalue) / advalue * CONTS_R;
    temp1 = log(restistance / refResistance) / CONST_B;
    temp2 = 1.0 / (CONST_T + ABSTEMP);
    temperature = 1.0 / (temp1 + temp2) - ABSTEMP;
    //Serial.println(restistance);
    //Serial.println(temp1, 8);
    //Serial.println(temp2, 8);
    return temperature;
}