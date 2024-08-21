#ifndef _DATABUFFER_H_
#define _DATABUFFER_H_

#include "Subject.hpp"
#include <vector>
#include "Record.hpp"

class DataBuffer : public Subject {
    public:
    DataBuffer(unsigned int m_r);
    struct Record getLastRecord();
    int append(struct Record);

    private:
    unsigned int max_records;
    std::vector<struct Record> records;

};

#endif