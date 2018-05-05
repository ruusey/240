/* Copyright 2018 */
#ifndef _LIB_INCLUDE_UTIL_H_  // NOLINT
#define _LIB_INCLUDE_UTIL_H_  // NOLINT

#include <cmath>
// using fabs

namespace csce240 {

namespace floating_point {
  const double kMaxAbsoluteError = 0.0001;
  const double kMaxRelativeError = 0.0001;

  bool Equals(double lhs, double rhs);
  inline bool equals(double lhs, double rhs) // deprecated
      { return Equals(lhs, rhs); }
}

}  // namespace csce240

#endif  // NOLINT
