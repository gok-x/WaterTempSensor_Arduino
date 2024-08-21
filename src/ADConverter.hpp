#ifndef _ADC_HPP_
#define _ADC_HPP_

class ADConverter {
    public:
    ADConverter(unsigned int i);
    unsigned int get_Data();

    private:
    unsigned int resolution;

};

#endif