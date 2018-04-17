/*
 * Author: Robert Usey
 * 04/12/2018
 * Homework 04
 * Copyright 2018
*/


#include <math.h>
#include "../include/quad_rotor.h"

namespace csce240 {

QuadRotor::QuadRotor(const Coordinate* location) {
    const three_dim::Point *point = dynamic_cast<const three_dim::Point *>(location);
    assert(point);
    this->location_ = new three_dim::Point(point->x(), point->y(), point->z());
    this->speed_ = 0.0;
}
QuadRotor::QuadRotor(const Coordinate* location, double speed) {
    const three_dim::Point *point = dynamic_cast<const three_dim::Point *>(location);
    assert(point);
    this->location_ = new three_dim::Point(point->x(), point->y(), point->z());
    this->speed_ = speed;
}
QuadRotor::QuadRotor(const double x, const double y, const double z) {
    this->location_ = new three_dim::Point(x, y, z);
    this->speed_ = 0.0;
}
QuadRotor::QuadRotor(double x, double y, const double z, double speed) {
    this->location_ = new three_dim::Point(x, y, z);
    this->speed_ = speed;
}
QuadRotor::~QuadRotor() {
    delete this->location_;
}

bool QuadRotor::CanTranslateTo(const Coordinate* goal) const {
    const three_dim::Point *end = dynamic_cast<const three_dim::Point *>(goal);
    const three_dim::Point *me = dynamic_cast<const three_dim::Point *>(this->location_);
    double xDif = (end->x() - me->x()) * (end->x() - me->x());
    double yDif = (end->y() - me->y()) * (end->y() - me->y());
    double zDif = (end->z() - me->z()) * (end->z() - me->z());
    return this->speed() >= sqrt(xDif+yDif+zDif);
}
void QuadRotor::Translate(const Offset* direction) {
    three_dim::Point *point = dynamic_cast<three_dim::Point *>(this->location_);
    point->AddOffset(direction);
}

} // namespace csce240


