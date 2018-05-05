/* Copyright 2018 LewisJS4@cse.sc.edu */
#ifndef _06HW_LIB_INCLUDE_SENSOR_NET_
#define _06HW_LIB_INCLUDE_SENSOR_NET_

#include <cstdlib>
// using rand
// using srand
#include <string>

namespace csce240 {

class SensorNet {
 public:
  // turn on sensor network and initialize sensors
  static void PowerOn();
  // currently only needs to set on status to false
  inline static void PowerOff() { on_ = false; }

  // true when the sensor net is running
  inline static bool on() {  return SensorNet::on_; }

  // public interface to sensor network
  static void ReadSensor(int sensor, int* size, char* bytes);
  static void UpdateSensor(int minutes=1);

  // number, names, and types of sensors
  enum SensorType {HUM=0, PRS=1, TMP=2};
  static const std::string k_sensor_names_[]; // "HUM", "PRS", and "TMP"
  static const int k_sensor_count_ = 3;

 private:
  // called by PowerOn
  static void InitHUM(int sensor);
  static void InitPRS(int sensor);
  static void InitTMP(int sensor);

  static bool on_;  // state of sensor network
  static SensorType sensors_[];  // corresponds with vals_ and holds each sensor
  static int vals_[];  // corresponds with sensors_ current value of each sensor

};

}  // namespace csce240

#endif
