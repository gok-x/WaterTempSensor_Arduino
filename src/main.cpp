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
}

void loop() {
  measurer->measure();
  delay(LOOP_INTERVAL_MSEC);
}
