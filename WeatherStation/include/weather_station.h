#ifndef _06HW_INCLUDE_WEATHER_STATION_H_
#define _06HW_INCLUDE_WEATHER_STATION_H_

#include <cassert>
#include <string>

#include "observable.h"
#include "../lib/include/sensor_net.h"

namespace csce240 {

class WeatherStation : public Observable {
 public:
   WeatherStation();
   virtual ~WeatherStation();

   double GetHumidity() const;
   double GetPressure() const;
   double GetTemperature() const;
 
};

}  // namespace csce240

#endif
