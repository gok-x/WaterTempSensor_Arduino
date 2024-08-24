#include "DataBuffer.hpp"

DataBuffer::DataBuffer(unsigned int m_r) : max_records(m_r){
    records = std::deque<struct Record>(m_r);
}
int DataBuffer::append(struct Record record){
    if(records.size() == max_records)
        records.pop_front();

    records.push_back(record);
    Notify();
    return 0;
}

struct Record DataBuffer::getLastRecord(){
    return records.back();
}