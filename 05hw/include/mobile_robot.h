/* Copyright 2018 */
#ifndef _05HW_INCLUDE_MOBILE_ROBOT_H_  // NOLINT
#define _05HW_INCLUDE_MOBILE_ROBOT_H_  // NOLINT

#include <cassert>
// using assert
#include <string>
#include <vector>

#include "point.h"        // NOLINT
#include "translation.h"  // NOLINT

namespace csce240 {

class MobileRobot {
 public:
  MobileRobot(const Translation* translation, const CartesianCoord* location);
  MobileRobot(const Translation* translation, const CartesianCoord* location,
      double speed);
  virtual ~MobileRobot();

  double speed() const;

  const std::string id() const;
  bool id(const std::string& id);

  bool CanTranslateTo(const CartesianCoord* goal) const;
  void Translate(const CartesianOffset* direction);

  void location(CartesianCoord* location) const;
  static std::string generateUUID();
  static bool IsUnique(const std::string& id);
 protected:
  const Translation *translation_;
  CartesianCoord *location_;
  double speed_;
  std::string id_;
};

}  // namespace csce240

#endif  // NOLINT
