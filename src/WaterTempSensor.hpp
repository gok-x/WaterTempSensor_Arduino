#ifndef _WATERTEMPSENSOR_HPP_
#define _WATERTEMPSENSOR_HPP_

#include "Sensor_IF.hpp"
#include "ADConverter.hpp"

class WaterTempSensor : public Sensor_IF{
    private:
    ADConverter* adc;
    public:
    WaterTempSensor(ADConverter* a);
    ~WaterTempSensor(){};

    int init();
    double read_data();
};

#endif