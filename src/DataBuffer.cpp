#include "DataBuffer.hpp"

DataBuffer::DataBuffer(unsigned int m_r){
    max_records = m_r;
    records = std::vector<struct Record>(m_r);
}
int DataBuffer::append(struct Record record){
    if(records.size() < max_records)
        records.erase(records.begin());

    records.push_back(record);
    Notify();
    return 0;
}

struct Record DataBuffer::getLastRecord(){
    return records.back();
}