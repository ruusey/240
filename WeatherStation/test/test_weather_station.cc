/* Copyright 2018 LewisJS4@cse.sc.edu */

#include <iostream>
#include <string>

#include "weather_station.h"

bool TestGetHumidity(const csce240::WeatherStation& station, std::string* err);
bool TestGetPressure(const csce240::WeatherStation& station, std::string* err);
bool TestGetTemperature(const csce240::WeatherStation& station,
                        std::string* err);

int main(int argc, char* argv[]) {
  csce240::WeatherStation station;
  std::string err;

  std::cout << "TESTING WEATHERSTATION" << std::endl;

  std::cout << "  TESTING WeatherStation::GetHumidity: ";
  if (TestGetHumidity(station, &err))
    std::cout << "PASSED" << std::endl;
  else {
    std::cout << "FAILED" << std::endl;
    std::cout << '\t' << err << std::endl;
    return 1;
  }

  std::cout << "  TESTING WeatherStation::GetPressure: ";
  if (TestGetPressure(station, &err))
    std::cout << "PASSED" << std::endl;
  else {
    std::cout << "FAILED" << std::endl;
    std::cout << '\t' << err << std::endl;
    return 1;
  }

  std::cout << "  TESTING WeatherStation::GetTemperature: ";
  if (TestGetTemperature(station, &err))
    std::cout << "PASSED" << std::endl;
  else {
    std::cout << "FAILED" << std::endl;
    std::cout << '\t' << err << std::endl;
    return 1;
  }

  return 0;
}

bool TestGetHumidity(const csce240::WeatherStation& station, std::string* err) {
  if (station.GetHumidity() == 70.00)
    return true;
  else {
    *err = "Expected: 70.00, Actual: " + std::to_string(station.GetHumidity());
    return false;
  }
}

bool TestGetPressure(const csce240::WeatherStation& station, std::string* err) {
  if (station.GetPressure() == 30.0499999999999999999999999999999)
    return true;
  else {
    *err = "Expected: 30.05, Actual: " + std::to_string(station.GetPressure());
    return false;
  }
}
bool TestGetTemperature(const csce240::WeatherStation& station,
                        std::string* err) {
  if (station.GetTemperature() == 17.2200000000000000000000000001181)
    return true;
  else {
    *err = "Expected: 17.22, Actual: "
        + std::to_string(station.GetTemperature());
    return false;
  } 
}
