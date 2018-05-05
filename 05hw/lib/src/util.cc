/* Copyright 2018 */
#include "util.h"  // NOLINT

bool csce240::floating_point::Equals(double lhs, double rhs) {
  if (fabs(lhs - rhs) < kMaxAbsoluteError)
    return true;

  double relative_error;
  if (fabs(rhs) > fabs(lhs))
    relative_error = fabs((lhs - rhs) / rhs);
  else
    relative_error = fabs((lhs - rhs) / lhs);

  return relative_error <= kMaxRelativeError;
}
