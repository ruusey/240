/* Copyright 2018 */

#include <iostream>

#include "point.h"
#include "vector.h"

using namespace csce240;

bool TestCreateTwoDimPoint();

bool TestCreateThreeDimPoint();

bool TestAddOffsetToCartesianCoord(const CartesianOffset& offset,
    const CartesianCoord& expected, CartesianCoord* coord);

bool TestGetOffsetFromCartesianCoord(const CartesianCoord& start,
    const CartesianCoord& end,const CartesianOffset& expected,
    CartesianOffset* actual);

bool TestCartesianCoordEquals(const CartesianCoord* lhs,
    const CartesianCoord* rhs, bool expected);

void TestCartesianCoordEquals();

bool TestCartesianCoordIsA(const CartesianCoord *lhs, const CartesianCoord *rhs,
    bool expected);

bool TestCartesianCoordGetDim(const CartesianCoord *lhs, int expected);

bool TestPoint2dVector2dAddOp(); 
bool TestPoint2dVector3dAddOp(); 
bool TestPoint3dVector3dAddOp();
bool TestPoint3dVector2dAddOp();

bool TestPoint2dPoint2dSubOp();
bool TestPoint2dPoint3dSubOp();
bool TestPoint3dPoint3dSubOp();
bool TestPoint3dPoint2dSubOp();

int main(int argc, char* argv[]) {
  /* Testing two_dim::Point creation */
  std::cout << "TESTING csce240::two_dim::Point CLASS" << std::endl;
  if (TestCreateTwoDimPoint())
    std::cout << " TestCreateTwoDimPoint PASSED" << std::endl;
  
  /* Testing three_dim::Point creation */
  std::cout << "TESTING csce240::three_dim::Point CLASS" << std::endl;
  if (TestCreateThreeDimPoint())
    std::cout << " TestCreateThreeDimPoint PASSED" << std::endl;

  /* Testing Add CartesianCoord methods with two_dim & three_dim points */
  std::cout << "TESTING csce240::CartesianCoord CLASS inheritance" << std::endl;
  if (TestAddOffsetToCartesianCoord(two_dim::Vector(2.0, 1.0),
      two_dim::Point(3.0, 3.0), new two_dim::Point(1.0, 2.0)))
    std::cout << " TestAddOffsetToCartesianCoord PASSED" << std::endl;

  if (TestAddOffsetToCartesianCoord(three_dim::Vector(2.0, 1.0, 2.5),
      three_dim::Point(3.0, 3.0, 3.0), new three_dim::Point(1.0, 2.0, 0.5)))
    std::cout << " TestAddOffsetToCartesianCoord PASSED" << std::endl;

  /* Testing Get CartesianCoord methods with two_dim & three_dim points */
  if (TestGetOffsetFromCartesianCoord(two_dim::Point(1.0, 1.0),
      two_dim::Point(0.0, 0.0), two_dim::Vector(-1.0, -1.0),
      new two_dim::Vector()))
    std::cout << " TestGetOffsetFromCartesianCoord PASSED" << std::endl;

  if (TestGetOffsetFromCartesianCoord(three_dim::Point(1.0, 1.0, -1.0),
      three_dim::Point(0.0, 0.0, 0.0), three_dim::Vector(-1.0, -1.0, 1.0),
      new three_dim::Vector()))
    std::cout << " TestGetOffsetFromCartesianCoord PASSED" << std::endl;

  /* Test Equals with two_dim::Points & three_dim::Points */
  std::cout << "TESTING csce240::CartesianCoord::Equals" << std::endl;
  TestCartesianCoordEquals();

  /* Test IsA with two_dim::Points and three_dim::Points */
  std::cout << "TESTING csce240::CartesianCoord::IsA" << std::endl;
  if (TestCartesianCoordIsA(new two_dim::Point(), new two_dim::Point(), true))
    std::cout << " TestCartesianCoordIsA PASSED" << std::endl;
  if (TestCartesianCoordIsA(new three_dim::Point(), new three_dim::Point(), true))
    std::cout << " TestCartesianCoordIsA PASSED" << std::endl;
  if (TestCartesianCoordIsA(new two_dim::Point(), new three_dim::Point(), false))
    std::cout << " TestCartesianCoordIsA PASSED" << std::endl;

  /* Test GetDim with two_dim::Points and three_dim::Points */
  std::cout << "TESTING csce240::CartesianCoord::GetDim" << std::endl;
  if (TestCartesianCoordGetDim(new two_dim::Point(), 2))
    std::cout << " TestCartesianCoordGetDim PASSED" << std::endl;
  if (TestCartesianCoordGetDim(new three_dim::Point(), 3))
    std::cout << " TestCartesianCoordGetDim PASSED" << std::endl;

  /* Test Add op for Point2d/3d and Vector2d/3d */
  std::cout << "TESTING csce240::two/three_dim::Point::operator+" << std::endl;
  if (TestPoint2dVector2dAddOp())
    std::cout << "  TestPoint2dVector2dAddOp PASSED" << std::endl;
  if (TestPoint2dVector3dAddOp())
    std::cout << "  TestPoint2dVector3dAddOp PASSED" << std::endl;
  if (TestPoint3dVector3dAddOp())
    std::cout << "  TestPoint3dVector3dAddOp PASSED" << std::endl;
  if (TestPoint3dVector2dAddOp())
    std::cout << "  TestPoint3dVector2dAddOp PASSED" << std::endl;

  /* Test Add op for Point2d/3d and Vector2d/3d */
  std::cout << "TESTTING csce240::two/three_dim::Point::operator-" << std::endl;
  if (TestPoint2dPoint2dSubOp())
    std::cout << "  TestPoint2dPoint2dSubOp PASSED" << std::endl;
  if (TestPoint2dPoint3dSubOp())
    std::cout << "  TestPoint2dPoint3dSubOp PASSED" << std::endl;
  if (TestPoint3dPoint3dSubOp())
    std::cout << "  TestPoint3dPoint3dSubOp PASSED" << std::endl;
  if (TestPoint3dPoint2dSubOp())
    std::cout << "  TestPoint3dPoint2dSubOp PASSED" << std::endl;
  return 0;
}

bool TestCreateTwoDimPoint() {
  two_dim::Point p2d(1.0, 0.5);
  CartesianCoord *c = p2d.Clone();

  if (1.0 != c->x() || 0.5 != c->y()) {
    std::cout << " TestCreateTwoDimPoint FAILED "
        << "Expected: (1.0, 0.5), Actual: " << *c << std::endl;
	delete c;
    return false;
  }

  three_dim::Point p3d(0.5, 1.0, 2.0);
  delete c;
  c = two_dim::Point(p3d).Clone();
  if (0.5 != c->x() || 1.0 != c->y() || 2 != c->GetDim()) {
    std::cout << " TestCreateTwoDimPoint FAILED "
        << "Expected: (0.5, 1.0), Actual: " << *c << std::endl;
    delete c;
    return false;
  }

  delete c;
  return true;
}

bool TestCreateThreeDimPoint() {
  three_dim::Point p3d(1.0, 0.5, 0.22);
  CartesianCoord *c = p3d.Clone();

  if (1.0 != c->x() || 0.5 != c->y() || 0.22 != c->z()) {
    std::cout << " TestCreateThreeDimPoint FAILED "
        << "Expected: (1.0, 0.5), Actual: " << c << std::endl;
    delete c;
    return false;
  }

  two_dim::Point p2d(0.5, 1.0);
  delete c;
  c = three_dim::Point(p2d).Clone();
  if (0.5 != c->x() || 1.0 != c->y() || 0.0 != c->z() || 3 != c->GetDim()) {
    std::cout << " TestCreateTwoDimPoint FAILED "
        << "Expected: (0.5, 1.0, 0.0), Actual: " << c << std::endl;
	delete c;
    return false;
  }

  delete c;
  return true;
}

bool TestAddOffsetToCartesianCoord(const CartesianOffset& offset,
    const CartesianCoord& expected, CartesianCoord* coord) {
  coord->AddOffset(&offset);

  if (!coord->Equals(&expected)) {
    std::cout << " TestAddOffsetToCartesianCoord FAILED "
        << "Expected: " << expected << ", Actual: " << *coord << std::endl;
    return false;
  }

  return true;
}

bool TestGetOffsetFromCartesianCoord(const CartesianCoord& start,
    const CartesianCoord& end, const CartesianOffset& expected,
    CartesianOffset* actual) {
  start.GetOffset(&end, actual);

  if (!expected.Equals(actual)) {
    std::cout << " TestGetOffsetFromCartesianCoord FAILED "
        << "Expected: " << expected << ", Actual: " << *actual << std::endl;
    return false;
  }

  return true;
}

bool TestCartesianCoordEquals(const CartesianCoord* lhs, const CartesianCoord* rhs,
    bool expected) {
  bool actual = lhs->Equals(rhs);
  if (actual != expected) {
    std::cout << " TestCartesianCoordEquals FAILED "
        << "Expected: " << expected << ", Actual: " << actual << std::endl;

    return false;
  }

  return true;
}

void TestCartesianCoordEquals() {
  CartesianCoord *p1, *p2;
  // good test two_dims
  p1 = new two_dim::Point(2.0/3.0, 1.0);
  p2 = new two_dim::Point(1.0 - 1.0/3.0, 1.0);
  if (TestCartesianCoordEquals(p1, p2, true))
    std::cout << " TestCartesianCoordEquals PASSED" << std::endl;

  // bad test two_dims
  delete p2;
  p2 = new two_dim::Point(5.0/6.0, 1.0);
  if (TestCartesianCoordEquals(p1, p2, false))
    std::cout << " TestCartesianCoordEquals PASSED" << std::endl;
  // good test three_dims
  delete p1;
  delete p2;

  p1 = new three_dim::Point(2.0/3.0, 0.0, 1.0);
  p2 = new three_dim::Point(1.0 - 1.0/3.0, 0.0, 1.0);
  if (TestCartesianCoordEquals(p1, p2, true))
    std::cout << " TestCartesianCoordEquals PASSED" << std::endl;
  // bad test three_dims
  delete p2;

  p2 = new three_dim::Point(5.0/6.0, 0.0, 1.0);
  if (TestCartesianCoordEquals(p1, p2, false))
    std::cout << " TestCartesianCoordEquals PASSED" << std::endl;
  // test two_dim & three_dim
  delete p2;

  p2 = new two_dim::Point(2.0/3.0, 0.0);
  if (TestCartesianCoordEquals(p1, p2, false))
    std::cout << " TestCartesianCoordEquals PASSED" << std::endl;
  delete p1;
  delete p2;
}

bool TestCartesianCoordIsA(const CartesianCoord *lhs, const CartesianCoord *rhs,
    bool expected) {
  if (lhs->IsA(rhs) != expected) {
    std::cout << " TestCartesianCoordIsA FAILED "
        << "Expected: " << expected << ", Actual: " << lhs->IsA(rhs)
        << std::endl;

    return false;
  }

  return true;
}

bool TestCartesianCoordGetDim(const CartesianCoord *lhs, int expected) {
  if (lhs->GetDim() != expected) {
    std::cout << " TestCartesianCoordGetDim FAILED "
        << "Expected: " << expected << ", Actual: " << lhs->GetDim()
        << std::endl;

    return false;
  }

  return true;
}

bool TestPoint2dVector2dAddOp() {
  two_dim::Point expected, p(-1.0, 0.5);
  two_dim::Vector v(1.0, -0.5);
  CartesianCoord *c = new two_dim::Point(p + v);
  if (!c->Equals(&expected)) {
    std::cout << " TestPoint2dVector2dAddOp FAILED "
        << "Expected: " << expected << ", Actual: " << *c << std::endl;
    delete c;
    return false;
  }

  delete c;
  return true;
}

bool TestPoint2dVector3dAddOp() {
  two_dim::Point p(-1.0, 0.5);
  three_dim::Point expected(0.0, 0.0, 2.7);
  three_dim::Vector v(1.0, -0.5, 2.7);
  CartesianCoord *c = new three_dim::Point(p + v);
  if (!c->Equals(&expected)) {
    std::cout << " TestPoint2dVector3dAddOp FAILED "
        << "Expected: " << expected << ", Actual: " << *c << std::endl;
    delete c;
    return false;
  }

  delete c;
  return true;
}

bool TestPoint3dVector3dAddOp() {
  three_dim::Point expected, p(-1.0, 0.5, 1.7);
  three_dim::Vector v(1.0, -0.5, -1.7);
  CartesianCoord *c = new three_dim::Point(p + v);
  if (!c->Equals(&expected)) {
    std::cout << " TestPoint3dVector3dAddOp FAILED "
        << "Expected: " << expected << ", Actual: " << *c << std::endl;
    delete c;
    return false;
  }

  delete c;
  return true;
}

bool TestPoint3dVector2dAddOp() {
  three_dim::Point expected(0.0, 0.0, 0.7), p(-1.0, 0.5, 0.7);
  two_dim::Vector v(1.0, -0.5);
  CartesianCoord *c = new three_dim::Point(p + v);
  if (!c->Equals(&expected)) {
    std::cout << " TestPoint3dVector2dAddOp FAILED "
        << "Expected: " << expected << ", Actual: " << *c << std::endl;
    delete c;
    return false;
  }

  delete c;
  return true;
}

bool TestPoint2dPoint2dSubOp() {
  two_dim::Point start, end(2.0, 1.7);
  CartesianOffset *expected = new two_dim::Vector(2.0, 1.7),
                  *actual = new two_dim::Vector(end - start);
  if (!actual->Equals(expected)) {
    std::cout << " TestPoint2dPoint2dSubOp FAILED "
        << "Expected: " << *expected << ", Actual: " << *actual << std::endl;

    delete expected;
    delete actual;
    return false;
  }

  delete expected;
  delete actual;
  return true;
}

bool TestPoint2dPoint3dSubOp() {
  three_dim::Point start(0.0, 0.0, -1.0);
  two_dim::Point end(2.0, 1.7);
  CartesianOffset *expected = new three_dim::Vector(2.0, 1.7, 1.0),
                  *actual = new three_dim::Vector(end - start);
  if (!actual->Equals(expected)) {
    std::cout << " TestPoint2dPoint3dSubOp FAILED "
        << "Expected: " << *expected << ", Actual: " << *actual << std::endl;

    delete expected;
    delete actual;
    return false;
  }

  delete expected;
  delete actual;
  return true;
}

bool TestPoint3dPoint3dSubOp() {
  three_dim::Point start(0.0, 0.0, -1.0);
  three_dim::Point end(2.0, 1.7, -1.0);
  CartesianOffset *expected = new three_dim::Vector(2.0, 1.7, 0.0),
                  *actual = new three_dim::Vector(end - start);
  if (!actual->Equals(expected)) {
    std::cout << " TestPoint2dPoint3dSubOp FAILED "
        << "Expected: " << *expected << ", Actual: " << *actual << std::endl;

    delete expected;
    delete actual;
    return false;
  }

  delete expected;
  delete actual;
  return true;
}

bool TestPoint3dPoint2dSubOp() {
  two_dim::Point start(0.0, 0.0);
  three_dim::Point end(2.0, 1.7, -1.0);
  CartesianOffset *expected = new three_dim::Vector(2.0, 1.7, -1.0),
                  *actual = new three_dim::Vector(end - start);
  if (!actual->Equals(expected)) {
    std::cout << " TestPoint2dPoint3dSubOp FAILED "
        << "Expected: " << *expected << ", Actual: " << *actual << std::endl;

    delete expected;
    delete actual;
    return false;
  }

  delete expected;
  delete actual;
  return true;
}

