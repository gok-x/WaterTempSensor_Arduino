#ifndef _WIFI_HPP_
#define _WIFI_HPP_
#include "WifiSecret.hpp"
#include <WiFiNINA_Generic.h>

class Wifi{
    int status;

    public:
    Wifi();
    int connect(const char* s = WIFI_SSID, const char* p = WIFI_PASSWD);
};

#endif