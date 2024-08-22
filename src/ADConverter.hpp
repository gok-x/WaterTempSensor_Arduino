#ifndef _ADC_HPP_
#define _ADC_HPP_
#include <ArduinoECCX08.h>

class ADConverter {
    public:
    ADConverter(unsigned int i, pin_size_t p);
    int get_Data();
    unsigned int get_resolution();

    private:
    unsigned int resolution;
    pin_size_t pin;

};

#endif