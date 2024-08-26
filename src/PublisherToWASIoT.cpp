#include "PublisherToAWSIoT.hpp"

PublisherToAWSIoT::PublisherToAWSIoT(DataBuffer* d, const char* ep, const char* cert): endpoint(ep), certificate(cert){
    subject = d;
    if(!intializeSSLClient())
        Serial.println("connection success!!");
    subject->Attach(this);
}

int PublisherToAWSIoT::intializeSSLClient(){
    WiFiClient client;
    sslClient = BearSSLClient(client);

    ArduinoBearSSL.onGetTime(getTime);

    sslClient.setEccSlot(0, certificate);

    Serial.println("Starting connection to server...");

    return sslClient.connect(endpoint, 443);
}

void PublisherToAWSIoT::Update(Subject* theChangedSubject){
    if (theChangedSubject == subject){
        if (publish(createJson(subject)))
            Serial.println("Publish failed.");
    }
}

String PublisherToAWSIoT::createJson(DataBuffer* databuffer){
    JsonDocument json;
    String output;
    Record record = databuffer->getLastRecord();
    json["time"] = record.time_msec;
    json["temperature"] = record.temperature;
    serializeJson(json, output);
    return output;
}

int PublisherToAWSIoT::publish(String data){
    return 0;
}

unsigned long PublisherToAWSIoT::getTime(){
    return WiFi.getTime();
}