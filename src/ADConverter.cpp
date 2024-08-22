#include "ADConverter.hpp"

ADConverter::ADConverter(unsigned int i, pin_size_t p){
    pinMode(p, INPUT);
    analogReadResolution(i);
    resolution = i;
    pin = p;
}

int ADConverter::get_Data(){
    //Serial.println("ADConverter.get_data() called");
    return analogRead(pin);
}
unsigned int ADConverter::get_resolution(){
    return resolution;
}