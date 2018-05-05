/* Copyright 2018 */

/* This pair of classes represent points in two and three space.
 * Classes contained:
 *  - csce240::Coordinate
 *    - csce240::CartesianCoord
 *      - csce240::two_dim::Point
 *      - csce240::three_dim::Point
 */
#ifndef _LIB_INCLUDE_POINT_H_  // NOLINT
#define _LIB_INCLUDE_POINT_H_  // NOLINT

#include <cassert>
#include <iostream>

#include "util.h"
#include "vector.h"

namespace csce240 {

class Coordinate {
 public:
  virtual ~Coordinate() {}  // delete Coordinate without warning

  virtual void AddOffset(const Offset* offset) = 0;
  virtual void GetOffset(const Coordinate* end, Offset* offset) const = 0;

  virtual bool Equals(const Coordinate* that) const = 0;
  virtual bool IsA(const Coordinate* that) const = 0;

  friend std::ostream& operator<<(std::ostream& lhs, const Coordinate& rhs);

 protected:
  virtual void ExtractTo(std::ostream& cout) const = 0;

};

// extraction operator for all children of Coordinate class
std::ostream& operator<<(std::ostream& lhs, const Coordinate& rhs);

class CartesianCoord : public Coordinate {
 public:
  CartesianCoord(double x, double y) : x_(x), y_(y) {}
  CartesianCoord(const CartesianCoord& that) : x_(that.x_), y_(that.y_) {}

  inline double x() const { return x_; }
  inline void x(double x) { x_ = x; }

  inline double y() const { return y_; }
  inline void y(double y) { y_ = y; }

  virtual ~CartesianCoord() {}  // delete CartesianCoord's without warning

  virtual CartesianCoord* Clone() const = 0;

  virtual double z() const = 0;
  virtual void z(double z) = 0;

  virtual int GetDim() const = 0;

 protected:
  double x_;
  double y_;
};

// forward declaration of the two_dim::Point
namespace two_dim{
  class Point;
}

// forward declaration of the three_dim::Point
namespace three_dim {
  class Point;
}

namespace two_dim {

/* Represents a point in two dimensions, with dimensions unspecified. */
class Point : public CartesianCoord {
 public:
  Point() : CartesianCoord(0.0, 0.0) {}
  Point(double x, double y) : CartesianCoord(x, y) {}
  Point(const CartesianCoord& that) : CartesianCoord(that) {}

  const Point operator+(const Vector& rhs) const;
  const three_dim::Point operator+(const three_dim::Vector& rhs) const;

  const Vector operator-(const Point& rhs) const;
  const three_dim::Vector operator-(const three_dim::Point& rhs) const;

  bool operator==(const Point& rhs) const;
  bool operator!=(const Point& rhs) const;

  /* Abstract methods from Coordinate  */
  void AddOffset(const Offset* offset);
  void GetOffset(const Coordinate* end, Offset* offset) const;

  bool Equals(const Coordinate* that) const;
  bool IsA(const Coordinate* that) const;

  /* Abstract methods from CartesianCoord  */
  inline double z() const { return 0.0; }
  inline void z(double z) { /* intentionally left empty */ }

  CartesianCoord* Clone() const;

  inline int GetDim() const { return 2; }

 protected:
  void ExtractTo(std::ostream& cout) const;

 private:
  const Point * ToPoint(const Coordinate* that) const;
};

}  // namespace two_dim

namespace three_dim {

/* Represents a point in three dimensions, with dimensions unspecified. */
class Point : public CartesianCoord {
 public:
  Point() : CartesianCoord(0.0, 0.0), z_(0.0) {}
  Point(double x, double y, double z) : CartesianCoord(x, y), z_(z) {}
  Point(const CartesianCoord& that) : CartesianCoord(that), z_(that.z()) {}

  const Point operator+(const Vector& rhs) const;
  const Point operator+(const two_dim::Vector& rhs) const;

  const Vector operator-(const Point& rhs) const;
  const Vector operator-(const two_dim::Point& rhs) const;

  bool operator==(const Point& rhs) const;
  bool operator!=(const Point& rhs) const;

  /* Abstract methods from Coordinate  */
  void AddOffset(const Offset* offset);
  void GetOffset(const Coordinate* end, Offset* offset) const;

  bool Equals(const Coordinate* that) const;
  bool IsA(const Coordinate* that) const;

  /* Abstract methods from CartesianCoord  */
  inline double z() const { return z_; }
  inline void z(double z) { z_ = z; }

  CartesianCoord* Clone() const;

  inline int GetDim() const { return 3; }

 protected:
  void ExtractTo(std::ostream& cout) const;

 private:
  const Point * ToPoint(const Coordinate* that) const;
  double z_;
};

}  // namespace three_dim

}  // namespace csce240

#endif  // NOLINT
