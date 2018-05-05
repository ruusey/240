/*
 * Copyright 2018
 * Created on: May 5, 2018
 * Author: Robert Usey
 * CSCE240 HW06
 */

#include <iostream> //NOLINT
#include <string.h> //NOLINT
#include "../include/weather_station.h" //NOLINT
namespace csce240 {
// Define our data offsets for sensor output (0-3 = data, 4-7 = sensor_type)
const int DATA_LENGTH = 4;
const int TYPE_OFFSET = 5;
const int TYPE_LENGTH = 3;
const int DECIMAL_OFFSET = 3;
const int WHOLE_OFFSET = 2;

int HUM_IDX = 0;
int PRS_IDX = 0;
int TMP_IDX = 0;
int IndexOfSensor(std::string sensor);
double FormatData(char *data);
WeatherStation::WeatherStation() {
  SensorNet::PowerOn();
  // Map the index for each sensor by doing a quick read of that sensor.
  HUM_IDX = IndexOfSensor("HUM");
  PRS_IDX = IndexOfSensor("PRS");
  TMP_IDX = IndexOfSensor("TMP");
}
WeatherStation::~WeatherStation() {
  SensorNet::PowerOff();
}

double WeatherStation::GetHumidity() const {
  int size = 0;
  // Alloc new char[] on heap to act as rval for ReadSensor
  char *data = new char[0]();
  SensorNet::ReadSensor(HUM_IDX, &size, data);
  return FormatData(data);
}
double WeatherStation::GetPressure() const {
  int size = 0;
  char *data = new char[0]();
  SensorNet::ReadSensor(PRS_IDX, &size, data);
  return FormatData(data);
}
double WeatherStation::GetTemperature() const {
  int size = 0;
  char *data = new char[0]();
  SensorNet::ReadSensor(TMP_IDX, &size, data);
  return FormatData(data);
}
int IndexOfSensor(std::string sensor) {
  for (int i = 0; i < 3; i++) {
    int size = 0;
    char *data = new char[0]();

    SensorNet::ReadSensor(i, &size, data);
    char type[TYPE_LENGTH + 1];
    memcpy(type, data + TYPE_OFFSET, TYPE_LENGTH);

    delete data;

    type[3] = '\0';
    std::string t(type);
    if (sensor == t) {
      return i;
    }

  }
  return -1;
}
// Formats the sensors data into a valid double
double FormatData(char *data) {
  char type[DATA_LENGTH + 1];

  memcpy(type, data, WHOLE_OFFSET);
  memcpy(type + DECIMAL_OFFSET, data + WHOLE_OFFSET, DATA_LENGTH);
  type[WHOLE_OFFSET] = '.';
  double dec = std::stod(type);
  delete data;
  return dec;
}                       //NOLINT
}  // namespace csce240 //NOLINT

