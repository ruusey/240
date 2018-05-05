#include "vector.h"

namespace csce240 {

std::ostream& operator<<(std::ostream& lhs, const Offset& rhs) {
  rhs.ExtractTo(lhs);

  return lhs;
}

namespace two_dim {

const Vector* Vector::ToVector(const Offset* that) const {
  const Vector *vector = dynamic_cast<const Vector *>(that);
  assert(vector);

  return vector;
}

const Vector& Vector::operator=(const CartesianOffset& that) {
  if (this != &that) {
    x_ = that.x();
	y_ = that.y();
  }

  return *this;
}

double Vector::GetLength() const {
  return sqrt(x_*x_ + y_*y_);
}

bool Vector::Equals(const Offset* that) const {
  const Vector *vector = ToVector(that);

  return floating_point::Equals(x_, vector->x_)
      && floating_point::Equals(y_, vector->y_);
}

bool Vector::IsA(const Offset* that) const {
  return nullptr != dynamic_cast<const Vector *>(that);
}

void Vector::GetUnit(Offset* that) const {
  Vector *vector = const_cast<Vector *>(ToVector(that));

  double magnitude = GetLength();
  assert(magnitude > 0.0);
  vector->x_ = x_ / magnitude;
  vector->y_ = y_ / magnitude;
}

void Vector::Scale(double scalar, Offset* scaled) const {
  Vector *vector = const_cast<Vector *>(ToVector(scaled));

  vector->x_ = scalar * x_;
  vector->y_ =  scalar * y_;
}

void Vector::ExtractTo(std::ostream& cout) const {
  cout << "(" << x_ << ", " << y_ << ")";
}

}  // namespace two_dim

namespace three_dim {

const Vector* Vector::ToVector(const Offset* that) const {
  const Vector *vector = dynamic_cast<const Vector *>(that);
  assert(vector);

  return vector;
}

const Vector& Vector::operator=(const CartesianOffset& that) {
  if (this != &that) {
    x_ = that.x();
	y_ = that.y();
	z_ = that.z();
  }

  return *this;
}

double Vector::GetLength() const {
  return sqrt(x_*x_ + y_*y_ + z_*z_);
}

bool Vector::Equals(const Offset* that) const {
  const Vector *vector = dynamic_cast<const Vector *>(that);
  assert(vector);

  return floating_point::Equals(x_, vector->x_)
      && floating_point::Equals(y_, vector->y_)
      && floating_point::Equals(z_, vector->z_);
}

bool Vector::IsA(const Offset* that) const {
  return nullptr != dynamic_cast<const Vector *>(that);
}

void Vector::GetUnit(Offset* that) const {
  Vector *vector = const_cast<Vector *>(ToVector(that));

  double magnitude = GetLength();
  assert(magnitude != 0.0);
  vector->x_ = x_ / magnitude;
  vector->y_ = y_ / magnitude;
  vector->z_ = z_ / magnitude;
}

void Vector::Scale(double scalar, Offset* scaled) const {
  Vector *vector = const_cast<Vector *>(ToVector(scaled));

  vector->x_ = scalar*x_;
  vector->y_ = scalar*y_;
  vector->z_ = scalar*z_;
}

void Vector::ExtractTo(std::ostream& cout) const {
  cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
}

}  // namespace three_dim


}  // namespace csce240
