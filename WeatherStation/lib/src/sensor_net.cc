#include "sensor_net.h"

namespace csce240 {
const std::string SensorNet::k_sensor_names_[] = { "HUM", "PRS", "TMP" };

bool SensorNet::on_ = false;
SensorNet::SensorType SensorNet::sensors_[SensorNet::k_sensor_count_];
int SensorNet::vals_[SensorNet::k_sensor_count_];

void SensorNet::PowerOn() {
  if (!SensorNet::on_) {
    srand(123);
    const int k_order_count = 6;
	  const SensorType orders[k_order_count][SensorNet::k_sensor_count_] =
	      { {HUM, PRS, TMP}, {HUM, TMP, PRS,}, {PRS, HUM, TMP}, {PRS, TMP, HUM},
          {TMP, HUM, PRS,}, {TMP, PRS, HUM} };

    int order = rand() % k_order_count;
    for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
      SensorNet::sensors_[i] = orders[order][i];
      switch (sensors_[i]) {
      case 0:  // set humidity to sensor i
        SensorNet::InitHUM(i);
        break;

      case 1:  // set pressure to sensor i
        SensorNet::InitPRS(i);
        break;

      case 2:  // set temperature to sensor i
        SensorNet::InitTMP(i);
        break;
      }
    }

    SensorNet::on_ = true;
  }
}

void SensorNet::InitHUM(int sensor) {
  sensors_[sensor] = HUM;
  vals_[sensor] = 7000; // 85.00%
}

void SensorNet::InitPRS(int sensor) {
  sensors_[sensor] = PRS;
  vals_[sensor] = 3005; // 30.05Hg
}

void SensorNet::InitTMP(int sensor) {
  SensorNet::sensors_[sensor] = TMP;
  vals_[sensor] = 1722; // 17.22 Celsius
}

void SensorNet::ReadSensor(int sensor, int* size, char* bytes) {
  std::string val = std::to_string(SensorNet::vals_[sensor]);
  std::string buffer = val + ' '
    + SensorNet::k_sensor_names_[SensorNet::sensors_[sensor]];

  *size = static_cast<int>(buffer.length());
  for (unsigned int i = 0; i < buffer.length(); ++i)
    bytes[i] = buffer.at(i);
}

void SensorNet::UpdateSensor(int minutes) {
  for (int i = 0; i < minutes; ++i)
    for (int j = 0; j < SensorNet::k_sensor_count_; ++j)
      if (TMP == sensors_[j])
        vals_[j] += 3;
      else
        vals_[j] -= 1;
}

}  // namespace csce240

