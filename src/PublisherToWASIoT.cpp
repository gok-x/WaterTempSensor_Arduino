#include "PublisherToAWSIoT.hpp"

PublisherToAWSIoT::PublisherToAWSIoT(DataBuffer* d, const char* ep, const int port, const char* cert): endpoint(ep), port(port), certificate(cert), sslClient(wifiClient){
    subject = d;
    if(!intializeSSLClient()){
        Serial.println("SSL connection failed");
        while(1);
    }
    subject->Attach(this);
    destination.concat(AWS_IOT_TOPIC);
    destination.concat("?qos=");
    destination.concat(AWS_IOT_QOS);
    //Serial.println(destination);
}

int PublisherToAWSIoT::intializeSSLClient(){
    ArduinoBearSSL.onGetTime(getTime);

    sslClient.setEccSlot(0, certificate);

    Serial.println("Starting connection to server...");

    return sslClient.connect(endpoint, port);
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
    sslClient.print("POST ");
    sslClient.print(destination);
    sslClient.println(" HTTP/1.1");
    sslClient.print("Host: ");
    sslClient.println(endpoint);
    sslClient.println("Content-Type: application/x-www-form-urlencoded");
    //sslClient.println("Connection: close");
    sslClient.print("Content-Length: ");
    sslClient.println(data.length());
    sslClient.println();
    sslClient.println(data);
    //Serial.print("connected:");
    //Serial.println(sslClient.connected());
    //Serial.print("available:");
    //Serial.println(sslClient.available()); 
    return 0;
}

unsigned long PublisherToAWSIoT::getTime(){
    return WiFi.getTime();
}