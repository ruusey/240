#ifndef _05HW_INCLUDE_TRANSLATION_H_  // NOLINT
#define _05HW_INCLUDE_TRANSLATION_H_  // NOLINT

#include "../lib/include/point.h"
#include "../lib/include/vector.h"

namespace csce240 {

class Translation {
 public:
  virtual ~Translation() {}

  virtual bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const = 0;

  virtual void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const = 0;
};

}  // namespace csce240

#endif  // NOLINT
