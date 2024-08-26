/*
  ECCX08 Random Number

  This sketch uses the ECC508 or ECC608 to generate a random number 
  every second and print it to the Serial Monitor

  Circuit:
   - MKR board with ECC508 or ECC608 on board

  created 19 July 2018
  by Sandeep Mistry
*/

#include <ArduinoECCX08.h>
#include "WaterTempMeasurer.hpp"
#include "WaterTempSensor.hpp"
#include "ADConverter.hpp"
#include "DataBuffer.hpp"
#include "Console.hpp"
#include "Wifi.hpp"
#include "PublisherToAWSIoT.hpp"
#include "Secret_Certificates.hpp"
#define LOOP_INTERVAL_MSEC 1000
#define ADC_RESOLUTION_BIT 12
#define MAX_DATA_RECORDS 1
#define ADC_INPUT_PIN A0
#define SENSOR_REFERENCE_RESISTANCE 10000U

ADConverter* adc;
DataBuffer* databuffer;
Console* console;
WaterTempSensor* sensor;
WaterTempMeasurer* measurer;
PublisherToAWSIoT* publisher;

char ssid[] = WIFI_SSID;                // your network SSID (name)
char pass[] = WIFI_PASSWD;                // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS; 

void setup() {
  Serial.begin(9600);
  while (!Serial);
  static ADConverter adcinstance(ADC_RESOLUTION_BIT, ADC_INPUT_PIN);
  static DataBuffer dbinstance(MAX_DATA_RECORDS);
  static Console consoleinstance(&dbinstance);
  static WaterTempSensor sensorinstance(&adcinstance, SENSOR_REFERENCE_RESISTANCE);
  static WaterTempMeasurer measurerinstance((Sensor_IF*)&sensorinstance, &dbinstance);

  adc = &adcinstance;
  databuffer = &dbinstance;
  console = &consoleinstance;
  sensor = &sensorinstance;
  measurer = &measurerinstance;

  Wifi wifi;
  wifi.connect();
  static PublisherToAWSIoT publisherinstance(databuffer, AWS_IOT_ENDPOINT, SECRET_CERTIFICATE);
  publisher = &publisherinstance;
}

void loop() {
  measurer->measure();
  delay(LOOP_INTERVAL_MSEC);
}
