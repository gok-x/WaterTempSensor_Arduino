#include "Wifi.hpp"

Wifi::Wifi(){
    status = WL_IDLE_STATUS;
    pinMode(LED_BUILTIN, OUTPUT);
}

int Wifi::connect(const char* ssid, const char* passwd){
    
    int trial = 0;
    const int max_trial = 5;
    digitalWrite(LED_BUILTIN, LOW);

    while(status != WL_CONNECTED && trial < max_trial){
        Serial.print("Attempting to connect to network: ");
        Serial.println(ssid);
        trial++;

        status = WiFi.begin(ssid, passwd);

        delay(10000);
    }

    if(trial >= max_trial){
        Serial.println("Connection failed.");
        return 1;
    }

    Serial.println("You're connected to the network");
    Serial.println("---------------------------------------");
    Serial.println("Board Information:");
    // print your board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print your network's SSID:
    Serial.println();
    Serial.println("Network Information:");
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.println(rssi);
    Serial.println("---------------------------------------");
    digitalWrite(LED_BUILTIN, HIGH);
    return 0;
}