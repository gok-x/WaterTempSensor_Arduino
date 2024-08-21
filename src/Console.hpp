#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include "DataBuffer.hpp"
#include "Observer.hpp"
#include <ArduinoECCX08.h>


class Console: public Observer{
public:
    Console(DataBuffer*);
    ~Console();
    
    void Update(Subject*);

private:
    DataBuffer* subject;

};

#endif