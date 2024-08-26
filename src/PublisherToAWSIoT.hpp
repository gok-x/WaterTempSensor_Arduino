#ifndef PUBLISHER_TO_AWSIOT_HPP
#define PUBLISHER_TO_AWSIOT_HPP

#include <ArduinoBearSSL.h>
#include <ArduinoECCX08.h>
#include <WiFiNINA_Generic.h>
#include <ArduinoJson.h>
#include "Secret_Certificates.hpp"
#include "DataBuffer.hpp"

class PublisherToAWSIoT : public Observer {
    DataBuffer* subject;
    const char* const endpoint;
    const char* const certificate;
    BearSSLClient sslClient;
    
    public:
    PublisherToAWSIoT(DataBuffer* d, const char* ep, const char* cert);
    int intializeSSLClient();
    void Update(Subject*);
    String createJson(DataBuffer* databuffer);
    int publish(String data);
    static unsigned long getTime();

};

#endif