#ifndef _05HW_INCLUDE_QUAD_ROTOR_TRANSLATION_H_  // NOLINT
#define _05HW_INCLUDE_QUAD_ROTOR_TRANSLATION_H_  // NOLINT

#include "../lib/include/point.h"
#include "translation.h"
#include "../lib/include/vector.h"

namespace csce240 {

class QuadRotorTranslation : public Translation {
 public:
  bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const;

  void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const;
};

namespace strict {

class QuadRotorTranslation : public Translation {
 public:
  bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const;

  void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const;
};

} // namespace strict

}  // namespace csce240

#endif  // NOLINT
