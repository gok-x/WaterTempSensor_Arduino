#include "Console.hpp"

Console::Console(DataBuffer* t){
    subject = t;
    subject->Attach(this);
}

Console::~Console(){
    subject->Detach(this);
}

void Console::Update(Subject* theChangedSubject){
    if(theChangedSubject == subject){
         Serial.print(subject->getLastRecord().time_msec);
         Serial.print("msec ");
         Serial.print(subject->getLastRecord().temperature);
         Serial.println("degree C");
    }
}