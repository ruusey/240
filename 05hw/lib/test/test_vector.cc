/* Copyright 2018 */

#include <cmath>
// using sqrt
#include <iostream>

#include "../include/point.h"
#include "../include/vector.h"

using namespace csce240;

bool TestCreateTwoDimVector();

bool TestCreateThreeDimVector();

bool TestGetLengthOfCartesianOffset(const csce240::CartesianOffset& o,
    double expected);

bool TestScaleCartesianOffset(const csce240::CartesianOffset& offset,
    double scalar, const csce240::CartesianOffset& expected,
    csce240::CartesianOffset* actual);

bool TestCartesianOffsetGetUnit(const csce240::CartesianOffset* offset,
    const csce240::CartesianOffset* expected, csce240::CartesianOffset* actual);

bool TestCartesianOffsetIsA(const CartesianOffset *lhs,
    const CartesianOffset *rhs, bool expected);

bool TestCartesianOffsetGetDim(const CartesianOffset *lhs, int expected);

int main(int argc, char* argv[]) {
  /* Test create two_dim::Vector */
  std::cout << "TESTING csce240::two_dim::Vector CLASS" << std::endl;
  if (TestCreateTwoDimVector())
    std::cout << " TestCreateTwoDimVector PASSED" << std::endl;

  /* Test create three_dim::Vector */
  std::cout << "TESTING csce240::three_dim::Vector CLASS" << std::endl;
  if (TestCreateThreeDimVector())
    std::cout << " TestCreateThreeDimVector PASSED" << std::endl;

  std::cout << "TESTING csce240::CartesianOffset CLASS inheritance" << std::endl;
  /* Test create two_dim::Vector::GetOffset */
  if (TestGetLengthOfCartesianOffset(two_dim::Vector(3.0, 4.0), 5.0))
    std::cout << " TestGetLengthOfTwoDimVector PASSED" << std::endl;

  /* Test create three_dim::Vector::GetOffset */
  if (TestGetLengthOfCartesianOffset(three_dim::Vector(3.0, 4.0, 12.0), 13.0))
    std::cout << " TestGetLengthOfThreeDimVector PASSED" << std::endl;

  CartesianOffset *offset = new two_dim::Vector();
  if (TestScaleCartesianOffset(two_dim::Vector(1.0, 1.0), 2.0,
      two_dim::Vector(2.0, 2.0), offset))
    std::cout << " TestScaleCartesianOffset PASSED" << std::endl;
  delete offset;

  offset = new three_dim::Vector();
  if (TestScaleCartesianOffset(three_dim::Vector(1.0, 1.0, 1.0), 2.0,
      three_dim::Vector(2.0, 2.0, 2.0), offset))
    std::cout << " TestScaleCartesianOffset PASSED" << std::endl;
  delete offset;

  /*
   * Test CartesianOffset::GetUnit
   */
  std::cout << "TESTING csce240::CartesianOffset::GetUnit" << std::endl;
  // good test two_dim
  offset = new two_dim::Vector(-3.0, 4.0);
  CartesianOffset *expected = new two_dim::Vector(-3.0/5.0, 4.0/5.0);
  CartesianOffset *actual = new two_dim::Vector();
  if (TestCartesianOffsetGetUnit(offset, expected, actual))
    std::cout << " TestCartesianOffsetGetUnit PASSED" << std::endl;
  delete offset;
  delete expected;
  delete actual;

  // good test three_dim
  offset = new three_dim::Vector(3.0, -4.0, 12.0);
  expected = new three_dim::Vector(3.0/13.0, -4.0/13.0, 12.0/13.0);
  actual = new three_dim::Vector();
  if (TestCartesianOffsetGetUnit(offset, expected, actual))
    std::cout << " TestCartesianOffsetGetUnit PASSED" << std::endl;
  delete offset;
  delete expected;
  delete actual;

  /* Test IsA with two_dim::Points and three_dim::Points */
  std::cout << "TESTING csce240::Vector::IsA" << std::endl;
  if (TestCartesianOffsetIsA(new two_dim::Vector(), new two_dim::Vector(), true))
    std::cout << " TestCartesianOffsetIsA PASSED" << std::endl;
  if (TestCartesianOffsetIsA(new three_dim::Vector(), new three_dim::Vector(), true))
    std::cout << " TestCartesianOffsetIsA PASSED" << std::endl;
  if (TestCartesianOffsetIsA(new two_dim::Vector(), new three_dim::Vector(), false))
    std::cout << " TestCartesianOffsetIsA PASSED" << std::endl;

  /* Test GetDim with two_dim::Points and three_dim::Points */
  std::cout << "TESTING csce240::Vector::GetDim" << std::endl;
  if (TestCartesianOffsetGetDim(new two_dim::Vector(), 2))
    std::cout << " TestCartesianOffsetGetDim PASSED" << std::endl;
  if (TestCartesianOffsetGetDim(new three_dim::Vector(), 3))
    std::cout << " TestCartesianOffsetGetDim PASSED" << std::endl;

  return 0;
}

bool TestCreateTwoDimVector() {
  two_dim::Vector v(1.0, 0.5);

  if (1.0 != v.x() || 0.5 != v.y()) {
    std::cout << " TestCreateTwoDimVector FAILED "
        << "Expected (1.0, 0.5), Actual: " << v << std::endl;
    return false;
  }

  return true;
}

bool TestCreateThreeDimVector() {
  three_dim::Vector v(1.0, 0.5, 0.22);

  if (1.0 != v.x() || 0.5 != v.y() || 0.22 != v.z()) {
    std::cout << " TestCreateThreeDimVector FAILED "
        << "Expected: (1.0, 0.5, 0.22) Actual: " << v << std::endl;
    return false;
  }

  return true;
}

bool TestGetLengthOfCartesianOffset(const csce240::CartesianOffset& o, double expected) {
  if (expected != o.GetLength()) {
    std::cout << " TestGetLengthOfCartesianOffset FAILED "
        << "Expected: " << expected << ", Actual: "
        << o.GetLength() << std::endl;
    return false;
  }

  return true;
}

/*
 * offset: a two_dim or three_dim vector which will be scaled
 * scalar: value by which offset will be scaled
 * expected: a vector which has been correctly scaled
 * scaled: a two_dim or three_dim vector which stores result of scale
 */
bool TestScaleCartesianOffset(const csce240::CartesianOffset& offset, double scalar,
    const csce240::CartesianOffset& expected, csce240::CartesianOffset* actual) {
  offset.Scale(scalar, actual);
  if (!expected.Equals(actual)) {
    std::cout << " TestScaleCartesianOffset FAILED Expected: " << expected
        << " Actual: " << *actual << std::endl;

    return false;
  }

  return true;
}

bool TestCartesianOffsetGetUnit(const csce240::CartesianOffset* offset,
    const csce240::CartesianOffset *expected, csce240::CartesianOffset* actual) {
  offset->GetUnit(actual);

  if (!csce240::floating_point::Equals(1.0, actual->GetLength())) {
    std::cout << " TestCartesianOffsetGetUnit FAILED Expected: length == 1.0 "
        << " Actual: length == " << actual->GetLength() << std::endl;

    return false;
  }

  if (!expected->Equals(actual)) {
    std::cout << " TestCartesianOffsetGetUnit FAILED Expected: " << *expected
        << " Actual: " << *actual << std::endl;

    return false;
  }

  return true;
}

bool TestCartesianOffsetIsA(const CartesianOffset *lhs,
    const CartesianOffset *rhs, bool expected) {
  if (lhs->IsA(rhs) != expected) {
    std::cout << " TestCartesianOffsetIsA FAILED "
        << "Expected: " << expected << ", Actual: " << lhs->IsA(rhs)
        << std::endl;

    return false;
  }

  return true;
}
bool TestCartesianOffsetGetDim(const CartesianOffset *lhs, int expected) {
  if (lhs->GetDim() != expected) {
    std::cout << " TestCartesianOffsetGetDim FAILED "
        << "Expected: " << expected << ", Actual: " << lhs->GetDim()
        << std::endl;

    return false;
  }

  return true;
};

