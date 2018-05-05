#ifndef _05HW_INCLUDE_TRACKED_TRANSLATION_H_  // NOLINT
#define _05HW_INCLUDE_TRACKED_TRANSLATION_H_  // NOLINT

#include "point.h"
#include "translation.h"
#include "vector.h"

namespace csce240 {

class TrackedTranslation : public Translation {
 public:
  bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const;

  void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const;
};

namespace strict {

class TrackedTranslation : public Translation {
 public:
  bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const;

  void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const;
};

}  // namespace strict

}  // namespace csce240

#endif  // NOLINT
