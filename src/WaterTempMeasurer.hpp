#ifndef _WATERTEMPMEASURER_HPP_
#define _WATERTEMPMEASURER_HPP_

#include "Sensor_IF.hpp"
#include "DataBuffer.hpp"

class WaterTempMeasurer {
    Sensor_IF* sensor;
    DataBuffer* databuffer;

    public:
    WaterTempMeasurer(Sensor_IF*, DataBuffer*);
    int measure();
};

#endif