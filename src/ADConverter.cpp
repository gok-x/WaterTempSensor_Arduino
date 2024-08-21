#include "ADConverter.hpp"
#include <ArduinoECCX08.h>

ADConverter::ADConverter(unsigned int i){
    resolution = i;
}

unsigned int ADConverter::get_Data(){
    Serial.println("ADConverter.get_data() called");
    return 35U;
}