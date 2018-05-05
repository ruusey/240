/*
 * Copyright 2018
 * Author: Robert Usey
 * 04/30/2018
 * Homework 05
 *
 */
#include <cassert>
#include <cstdlib>
// using atoi
#include <iostream>
#include <string>

#include "../include/mobile_robot.h"
#include "../include/quad_rotor_translation.h"
#include "../include/tracked_translation.h"
#include "../lib/include/point.h"
#include "../lib/include/vector.h"

bool TestTrackedCreation();

bool TestMobileRobotIsUnique();

bool TestMobileRobotSetId();

bool TestMobileRobotCanTranslateTo(const csce240::MobileRobot* robot,
                                   const csce240::Coordinate* coord,
                                   bool expected);

bool TestMobileRobotTranslate(csce240::MobileRobot* robot,
                              const csce240::Offset* offset,
                              const csce240::Coordinate* expected);

int main(int argc, char* argv[]) {
  //assert(false && "The test_mobile_robot.cc is almost entirely commented out. You should update methods to work with the new class interfaces.");
  // std::co
  csce240::two_dim::Point *p0 = new csce240::two_dim::Point(1.0, 1.0);
  csce240::strict::TrackedTranslation *t0 =
      new csce240::strict::TrackedTranslation();
  double speed = 3.0;

  csce240::MobileRobot *r0 = new csce240::MobileRobot(t0, p0, speed);
  csce240::two_dim::Vector *p1 = new csce240::two_dim::Vector(1.5, 1.5);
  r0->Translate(p1);

  csce240::three_dim::Point *p2 = new csce240::three_dim::Point(1.0, 1.0, 1.0);
  csce240::QuadRotorTranslation *t1 = new csce240::QuadRotorTranslation();
  double speed1 = 1.0;

  csce240::MobileRobot *r1 = new csce240::MobileRobot(t1, p2, speed1);
  csce240::three_dim::Vector *p4 = new csce240::three_dim::Vector(1.5, 1.5,
                                                                  10.5);
  csce240::two_dim::Vector *p5 = new csce240::two_dim::Vector(5.0, 5.0);
  r1->Translate(p5);

//  if (TestTrackedCreation())
//    std::cout << "\t PASSED" << std::endl;
//  else
//    return 1;
//
//  if (TestMobileRobotIsUnique())
//    std::cout << "\t PASSED" << std::endl;
//  else
//    return 1;
//
//  if (TestMobileRobotSetId())
//    std::cout << "\t PASSED" << std::endl;
//  else
//    return 1;

  /* Test MobileRobot::CanTranslateTo */
  // c = new csce240::two_dim::Point();  // robot origin
  // r = new csce240::Tracked(c, 5.0);  // robot at origin
  // delete c;  // prepare to hold expected
  // c = new csce240::two_dim::Point(3.0, 4.0);  // goal location
  // if (TestMobileRobotCanTranslateTo(r, c, true))  // good test
  //   std::cout << "\t PASSED" << std::endl;
  // else
  //   return 1;
  // delete c;
  // c = new csce240::two_dim::Point(-3.01, -4.01);  // goal location
  // if (TestMobileRobotCanTranslateTo(r, c, false))  // bad test
  //   std::cout << "\t PASSED" << std::endl;
  // else
  //   return 1;
  // delete c;
  /* Test MobileRobot::Translate */
  // o = new csce240::two_dim::Vector(3.0, 4.0);
  // c = new csce240::two_dim::Point(3.0, 4.0);
  // if (TestMobileRobotTranslate(r, o, c)) // good test
  //   std::cout << "\t PASSED" << std::endl;
  // delete c;
  // o->Scale(-1.01, o);
  // c = new csce240::two_dim::Point(0.0, 0.0);
  // if (TestMobileRobotTranslate(r, o, c)) // bad test
  //   std::cout << "\t PASSED" << std::endl;
  // delete c;
  // delete r;
  // delete o;
  return 0;
}

bool TestTrackedCreation() {
  std::cout << "\tTestTrackedCreation" << std::endl;
  // csce240::Coordinate *p = new csce240::two_dim::Point(0.0, 0.0);
  // csce240::MobileRobot *r = new csce240::Tracked(p, 5.0);
  // dynamic_cast<csce240::two_dim::Point *>(p)->x(1.0);

  // csce240::two_dim::Point q;
  // r->location(&q);
  // if (q.Equals(p)) {
  //   std::cout << "\t FAILED" << std::endl;
  //   std::cout << "\t Point expected: " << *p
  //       << ", actual: " << q << std::endl;

  return false;
  // }

  // delete p;
  // delete r;
  // return true;
}

bool TestMobileRobotIsUnique() {
  std::cout << "\tTestMobileRobotIsUnique" << std::endl;

  // if (!csce240::MobileRobot::IsUnique("id")) {
  //   std::cout << "\t FAILED" << std::endl;
  //   std::cout << "\t csce240::Tracked::IsUnique(\"id\")"
  //       << " Expected: 1, Actual: " << !csce240::MobileRobot::IsUnique("id")
  //       << std::endl;

  //   return false;
  // }

  //csce240::MobileRobot r(0.0, 0.0);
  //std::string id = r.id();
  //if (csce240::Tracked::IsUnique(id)) {
  //  std::cout << "\t FAILED" << std::endl;
  //  std::cout << "\t csce240::Tracked::IsUnique(" << id
  //      << ") Expected: 0, Actual: " << csce240::Tracked::IsUnique(id)
  //      << std::endl;

  //  return false;
  //}

  return true;
}

bool TestMobileRobotSetId() {
  std::cout << "\tTestMobileRobotSetId" << std::endl;
  //csce240::MobileRobot r1(0.0, 0.0), r2(0.0, 0.0);

  //if (!r1.id("id")) {
  //  std::cout << "\t FAILED" << std::endl;
  //  std::cout << "\t r1.id(\"id\") Expected: 1, Actual: " << !r1.id("id")
  //      << std::endl;
  //  return false;
  //}

  //if (r2.id("id")) {
  //  std::cout << "\t FAILED" << std::endl;
  //  std::cout << "\t r2.id(\"id\") Expected: 0, Actual: " << r2.id("id")
  //      << std::endl;

  return false;
  //}

  // return true;
}

bool TestMobileRobotCanTranslateTo(const csce240::MobileRobot* robot,
                                   const csce240::Coordinate* coord,
                                   bool expected) {
  std::cout << "\tTestMobileRobotCanTranslateTo" << std::endl;

  // if (robot->CanTranslateTo(coord) != expected) {
  //   std::cout << "\t FAILED" << std::endl;
  //   std::cout << "\t Translate from " << *(robot->location())
  //       << ", to " << *coord
  //       << " with speed " << robot->speed()
  //       << " Expected: 0, Actual: " << (robot->CanTranslateTo(coord)!=expected)
  //       << std::endl;
  return false;
  // }

  // return true;
}

bool TestMobileRobotTranslate(csce240::MobileRobot* robot,
                              const csce240::Offset* offset,
                              const csce240::Coordinate* expected) {
  std::cout << "\tTestMobileRobotTranslate" << std::endl;

  // robot->Translate(offset);
  // if (!robot->location()->Equals(expected)) {
  //   std::cout << "\t FAILED" << std::endl;
  //   std::cout << "\t Expected: " << *expected 
  //       << ", Actual: " << *(robot->location()) << std::endl;
  return false;
  // }

  // return true;
}

