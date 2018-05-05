/*
 * Copyright 2018
 * Author: Robert Usey
 * 04/30/2018
 * Homework 05
 *
 */
#include "../lib/include/point.h"
#include "../lib/include/vector.h"
#include "../include/quad_rotor_translation.h"
namespace csce240 {

bool QuadRotorTranslation::CanTranslateTo(const CartesianCoord* start,
                                          const double speed,
                                          const CartesianCoord* goal) const {

  if (goal->GetDim() != 3) {
    const CartesianCoord *gol = new three_dim::Point(goal->x(), goal->y(), 0.0);
    goal = gol;
  } else if (start->GetDim() != 3) {
    const CartesianCoord *strt = new three_dim::Point(start->x(), start->y(),
                                                      0.0);
    start = strt;
  }
  CartesianOffset *offset = new three_dim::Vector();
  start->GetOffset(goal, offset);

  if (offset->GetLength() > speed) {
    std::cout << "QuadRotor cannot move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return false;
  } else {
    std::cout << "QuadRotor can move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return true;
  }
}

void QuadRotorTranslation::Translate(const CartesianOffset* direction,
                                     const double speed,
                                     CartesianCoord* start) const {
  if (direction->GetDim() != 3) {
    const CartesianOffset *gol = new three_dim::Vector(direction->x(),
                                                       direction->y(), 0.0);
    direction = gol;
  }
  CartesianCoord *end = start->Clone();

  end->AddOffset(direction);

  if (CanTranslateTo(start, speed, end)) {
    delete start;
    start = end;
    std::cout << "QuadRotor location is now " << *start << std::endl;
  } else {
    delete end;
    std::cout << "QuadRotor failed to translate!" << std::endl;
  }

}
namespace strict {
bool QuadRotorTranslation::CanTranslateTo(const CartesianCoord* start,
                                          const double speed,
                                          const CartesianCoord* goal) const {
  if (goal->GetDim() != 3) {
    std::cout << "QuadRotor STRICT unable to translate to higher dimension!"
              << std::endl;
    return false;
  } else if (start->GetDim() != 3) {
    std::cout << "QuadRotor STRICT unable to translate to higher dimension!"
              << std::endl;
    return false;
  }

  three_dim::Vector *offset;
  start->GetOffset(goal, offset);

  if (offset->GetLength() > speed) {
    std::cout << "QuadRotor cannot move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    //delete (offset);
    return false;
  } else {
    std::cout << "QuadRotor can move from " << *start << " to " << *goal
              << " (required_speed=" << offset->GetLength() << ", my_speed="
              << speed << ")" << std::endl;
    delete (offset);
    return true;
  }

}

void QuadRotorTranslation::Translate(const CartesianOffset* direction,
                                     const double speed,
                                     CartesianCoord* start) const {
  if (direction->GetDim()) {
    std::cout << "QuadRotor STRICT unable to translate to different dimension!"
              << std::endl;
    return;
  }
  CartesianCoord *end = (start->Clone());
  end->AddOffset(direction);

  if (CanTranslateTo(start, speed, end)) {

    start = end;
    std::cout << "QuadRotor location is now " << *start << std::endl;
  } else {
    delete end;
    std::cout << "QuadRotor failed to translate!" << std::endl;
  }
}

}
}

