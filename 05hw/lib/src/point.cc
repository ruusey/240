#include "point.h"

namespace csce240 {

std::ostream& operator<<(std::ostream& lhs, const Coordinate& rhs) {
  rhs.ExtractTo(lhs);

  return lhs;
}

namespace two_dim {

const Point Point::operator+(const Vector& rhs) const {
  return Point(x_ + rhs.x(), y_ + rhs.y());
}

const three_dim::Point Point::operator+(const three_dim::Vector& rhs) const {
  return three_dim::Point(x_ + rhs.x(), y_ + rhs.y(), 0.0 + rhs.z());
}

/* "The vector from lhs to rhs is given by rhs - lhs" */
const Vector Point::operator-(const Point& rhs) const {
  return Vector(x_ - rhs.x(), y_ - rhs.y());
}

const three_dim::Vector Point::operator-(const three_dim::Point& rhs) const {
  return three_dim::Vector(x_ - rhs.x(), y_ - rhs.y(), 0.0 - rhs.z());
}

bool Point::operator==(const Point& rhs) const {
  return floating_point::equals(x_, rhs.x_)
      && floating_point::equals(y_, rhs.y_);
}

bool Point::operator!=(const Point& rhs) const {
  return !floating_point::equals(x_, rhs.x_)
      || !floating_point::equals(y_, rhs.y_);
}

void Point::AddOffset(const Offset* offset) {
  const Vector *vector = dynamic_cast<const Vector *>(offset);
  assert(vector);

  x_ += vector->x();
  y_ += vector->y();
}

void Point::GetOffset(const Coordinate* end, Offset* offset) const {
  const Point *point = ToPoint(end);
  Vector *vector = dynamic_cast<Vector *>(offset);
  assert(vector);

  vector->x(point->x_ - x_);
  vector->y(point->y_ - y_);
}

bool Point::Equals(const Coordinate* that) const {
  const Point *point = dynamic_cast<const Point *>(that);
  if (nullptr == point)
    return false;

  return *this == *point;
}

bool Point::IsA(const Coordinate* that) const {
  return nullptr != dynamic_cast<const Point *>(that);
}

CartesianCoord* Point::Clone() const {
  return new Point(x_, y_);
}

void Point::ExtractTo(std::ostream& cout) const {
  cout << "(" << x_ << ", " << y_ << ")";
}

const Point * Point::ToPoint(const Coordinate* that) const {
  const Point *point = dynamic_cast<const Point *>(that);
  assert(point);

  return point;
}

}  // namespace two_dim

namespace three_dim {

const Point Point::operator+(const Vector& rhs) const {
  return Point(x_ + rhs.x(), y_ + rhs.y(), z_ + rhs.z());
}

const Point Point::operator+(const two_dim::Vector& rhs) const {
  return Point(x_ + rhs.x(), y_ + rhs.y(), z_ + 0.0);
}

const Vector Point::operator-(const Point& rhs) const {
  return Vector(x_ - rhs.x(), y_ - rhs.y(), z_ - rhs.z());
}

const Vector Point::operator-(const two_dim::Point& rhs) const {
  return Vector(x_ - rhs.x(), y_ - rhs.y(), z_ - rhs.z());
}

bool Point::operator==(const Point& rhs) const {
  return floating_point::equals(x_, rhs.x_)
      && floating_point::equals(y_, rhs.y_)
      && floating_point::equals(z_, rhs.z_);
}

bool Point::operator!=(const Point& rhs) const {
  return !floating_point::equals(x_, rhs.x_)
      || !floating_point::equals(y_, rhs.y_)
      || !floating_point::equals(z_, rhs.z_);
}

void Point::AddOffset(const Offset* offset) {
  const Vector *vector = dynamic_cast<const Vector *>(offset);
  assert(vector);

  x_ += vector->x();
  y_ += vector->y();
  z_ += vector->z();
}

void Point::GetOffset(const Coordinate* end, Offset* offset) const {
  const Point *point = ToPoint(end);

  Vector *vector = dynamic_cast<Vector *>(offset);
  assert(vector);

  vector->x(point->x_ - x_);
  vector->y(point->y_ - y_);
  vector->z(point->z_ - z_);
}

bool Point::Equals(const Coordinate* that) const {
  const Point *point = dynamic_cast<const Point *>(that);
  if (nullptr == point)
    return false;

  return *this == *point;
}

bool Point::IsA(const Coordinate* that) const {
  return nullptr != dynamic_cast<const Point *>(that);
}

CartesianCoord* Point::Clone() const {
  return new Point(x_, y_, z_);
}

void Point::ExtractTo(std::ostream& cout) const {
  cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
}

const Point * Point::ToPoint(const Coordinate* that) const {
  const Point *point = dynamic_cast<const Point *>(that);
  assert(point);

  return point;
}

}  // namespace three_dim

}  // namespace csce240
