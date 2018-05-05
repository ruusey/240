/* Copyright 2018 */

/* This pair of classes represent vectors in two and three space.
 * Classes contained:
 *  - csce240::Offset
 *  - csce240::CartesianOffset
 *  - csce240::two_dim::Vector
 *  - csce240::three_dim::Vector
 */
#ifndef _LIB_INCLUDE_VECTOR_H_  // NOLINT
#define _LIB_INCLUDE_VECTOR_H_  // NOLINT

#include <cassert>
#include <cmath>
// using sqrt
#include <iostream>
#include <string>

#include "util.h"

namespace csce240 {

/* Child classes only needed for accessors and mutators */
class Offset {
 public:
  virtual ~Offset() {};  // delete Offsets without warnings

  virtual double GetLength() const = 0;
  virtual bool Equals(const Offset* that) const = 0;
  virtual bool IsA(const Offset* that) const = 0;
  virtual void GetUnit(Offset* unit) const = 0;
  virtual void Scale(double scalar, Offset* scaled) const = 0;

  friend std::ostream& operator<<(std::ostream& lhs, const Offset& rhs);

 protected:
  virtual void ExtractTo(std::ostream& cout) const = 0;

};

std::ostream& operator<<(std::ostream& lhs, const Offset& rhs);

class CartesianOffset : public Offset {
 public:
  CartesianOffset(double x, double y) : x_(x), y_(y) {}

  inline double x() const { return x_; }
  inline double y() const { return y_; }

  inline void x(double x) { x_ = x; }
  inline void y(double y) { y_ = y; }

  virtual ~CartesianOffset() {};  // delete Offsets without warnings

  virtual double z() const = 0;
  virtual void z(double z) = 0;

  virtual int GetDim() const = 0;

 protected:
  virtual void ExtractTo(std::ostream& cout) const = 0;

  double x_;
  double y_;
};

namespace two_dim {

class Vector : public CartesianOffset {
 public:
  Vector() : CartesianOffset(0.0, 0.0) {}
  Vector(double x, double y) : CartesianOffset(x, y) {}
  Vector(const CartesianOffset& that) : CartesianOffset(that.x(), that.y()) {}

  const Vector& operator=(const CartesianOffset& that);
 
  /* Abstract methods from Offset */
  double GetLength() const;
  void GetUnit(Offset* unit) const;
  void Scale(double scalar, Offset* scaled) const;
  bool Equals(const Offset* that) const;
  bool IsA(const Offset* that) const;

  /* Abstract methods from CartesianOffset */
  inline double z() const { return 0.0; }
  inline void z(double z) { /* intentionally left empty */ }

  inline int GetDim() const { return 2; }

 protected:
  void ExtractTo(std::ostream& cout) const;

 private:
  const Vector* ToVector(const Offset* that) const;
};

}  // namespace two_dim
  
namespace three_dim {

class Vector : public CartesianOffset {
 public:
  Vector() : CartesianOffset(0.0, 0.0), z_(0.0) {}
  Vector(double x, double y, double z) : CartesianOffset(x, y), z_(z) {}
  Vector(const CartesianOffset& that) : CartesianOffset(that), z_(that.z()) {}

  const Vector& operator=(const CartesianOffset& that);
 
  /* Abstract methods from Offset */
  double GetLength() const;
  void GetUnit(Offset* unit) const;
  void Scale(double scalar, Offset* scaled) const;
  bool Equals(const Offset* that) const;
  bool IsA(const Offset* that) const;

  /* Abstract methods from CartesianOffset */
  inline double z() const { return z_; }
  inline void z(double z) { z_ = z; }

  inline int GetDim() const { return 3; }

 protected:
  void ExtractTo(std::ostream& cout) const;
  const Vector* ToVector(const Offset* that) const;

 private:
  double z_;
};

}  // namespace three_dim

}  // namespace csce240

#endif  // NOLINT
