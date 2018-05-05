/* Copyright 2018 LewisJS4@cse.sc.edu */

#include <iostream>
using std::cout;
using std::endl;

#include "sensor_net.h"
using csce240::SensorNet;

int main(int argc, char* argv[]) {
  cout << "TESTING SENSOR NETWORK\n" << endl;

  cout << " Sensor names: ";
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i)
    cout << SensorNet::k_sensor_names_[i] << ' ';
  cout << '\n' << endl;

  SensorNet::PowerOn();
  int size = 0;
  char *buffer = new char[8];
  cout << " Initial:" << endl;
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
    SensorNet::ReadSensor(i, &size, buffer);
    cout << "  " << buffer << endl;
  }
  cout << endl;

  SensorNet::UpdateSensor(60);
  cout << " After 1 Hour:" << endl;
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
    SensorNet::ReadSensor(i, &size, buffer);
    cout << "  " << buffer << endl;
  }
  cout << endl;

  SensorNet::UpdateSensor(60);
  cout << " After 2 Hours:" << endl;
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
    SensorNet::ReadSensor(i, &size, buffer);
    cout << "  " << buffer << endl;
  }
  cout << endl;

  return 0;
}


