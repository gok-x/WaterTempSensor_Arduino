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
#define MAX_DATA_RECORDS 50

ADConverter* adc;
DataBuffer* databuffer;
Console* console;
WaterTempSensor* sensor;
WaterTempMeasurer* measurer;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  adc = new ADConverter(ADC_RESOLUTION_BIT);
  databuffer = new DataBuffer(MAX_DATA_RECORDS);
  console = new Console(databuffer);
  sensor = new WaterTempSensor(adc);
  measurer = new WaterTempMeasurer((Sensor_IF*)sensor, databuffer);
}

void loop() {
  measurer->measure();
  delay(LOOP_INTERVAL_MSEC);
}
