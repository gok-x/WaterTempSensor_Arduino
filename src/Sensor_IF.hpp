#ifndef _SENSOR_IF_H_
#define _SENSOR_IF_H_

class Sensor_IF{
    public:
    virtual ~Sensor_IF();
    virtual int init() = 0;
    virtual double read_data() = 0;

    protected:
    Sensor_IF();
};
#endif