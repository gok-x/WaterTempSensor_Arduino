#ifndef _WATERTEMPSENSOR_HPP_
#define _WATERTEMPSENSOR_HPP_

#include "Sensor_IF.hpp"
#include "ADConverter.hpp"
#define ABSTEMP 273
#define CONST_B 3435
#define CONST_T 25
#define CONTS_R 10000
#define NUMSHOTS 10

class WaterTempSensor : public Sensor_IF{
    private:
    ADConverter* adc;
    unsigned int refResistance;
    public:
    WaterTempSensor(ADConverter* a, unsigned int rR);
    ~WaterTempSensor(){};

    int init();
    double read_data();
    double calc_temperature(int advalue);
};

#endif