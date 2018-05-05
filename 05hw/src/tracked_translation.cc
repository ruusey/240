/*
 * Copyright 2018
 * Author: Robert Usey
 * 04/30/2018
 * Homework 05
 *
 */
#include "../lib/include/point.h"
#include "../lib/include/vector.h"
#include "../include/tracked_translation.h"
namespace csce240 {

bool TrackedTranslation::CanTranslateTo(const CartesianCoord* start,
                                        const double speed,
                                        const CartesianCoord* goal) const {
  if (goal->GetDim() != 2 && start->GetDim() == 2) {
    const CartesianCoord *strt = new three_dim::Point(start->x(), start->y(),
                                                      0.0);
    start = strt;
  }
  CartesianOffset *offset = new three_dim::Vector();
  start->GetOffset(goal, offset);

  if (offset->GetLength() > speed) {
    std::cout << "TrackedRobot cannot move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return false;
  } else {
    std::cout << "TrackedRobot can move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return true;
  }

}

void TrackedTranslation::Translate(const CartesianOffset* direction,
                                   const double speed,
                                   CartesianCoord* start) const {

  three_dim::Point *end = new three_dim::Point(start->x(), start->y(), 0.0);

  end->AddOffset(direction);

  if (CanTranslateTo(start, speed, end)) {
    delete start;
    start = end;
    std::cout << "TrackedRobot location is now " << *start << std::endl;
  } else {
    delete end;
    std::cout << "TrackedRobot failed to translate!" << std::endl;
  }

}
namespace strict {
bool TrackedTranslation::CanTranslateTo(const CartesianCoord* start,
                                        const double speed,
                                        const CartesianCoord* goal) const {
  if (goal->GetDim() != 2) {
    std::cout << "TrackedRobot STRICT unable to translate to higher dimension!"
              << std::endl;
    return false;
  }
  two_dim::Vector *offset;
  start->GetOffset(goal, offset);

  if (offset->GetLength() > speed) {
    std::cout << "TrackedRobot cannot move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return false;
  } else {
    std::cout << "TrackedRobot can move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return true;
  }

}

void TrackedTranslation::Translate(const CartesianOffset* direction,
                                   const double speed,
                                   CartesianCoord* start) const {

  if (direction->GetDim() != 2) {
    std::cout << "TrackedRobot STRICT unable to translate to higher dimension!"
              << std::endl;
    return;
  }
  CartesianCoord *end = (start->Clone());
  end->AddOffset(direction);

  if (CanTranslateTo(start, speed, end)) {

    start = end;
    std::cout << "TrackedRobot location is now " << *start << std::endl;
  } else {

    std::cout << "TrackedRobot failed to translate!" << std::endl;
  }

}
}
}
