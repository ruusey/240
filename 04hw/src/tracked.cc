/*
 * Author: Robert Usey
 * 04/12/2018
 * Homework 04
 * Copyright 2018
*/

#include <math.h>
#include "../include/tracked.h"

namespace csce240 {
Tracked::Tracked(const Coordinate* location) {
    const two_dim::Point *point = dynamic_cast<const two_dim::Point *>(location);
    assert(point);
    this->location_ = new two_dim::Point(point->x(), point->y());

    this->speed_ = 0.0;
}
Tracked::Tracked(const Coordinate* location, double speed) {
    const two_dim::Point *point = dynamic_cast<const two_dim::Point *>(location);
    assert(point);
    this->location_ = new two_dim::Point(point->x(), point->y());
    this->speed_ = speed;
}
Tracked::Tracked(const double x, const double y) {
    this->location_ = new two_dim::Point(x, y);
    this->speed_ = 0.0;
}
Tracked::Tracked(double x, double y, double speed) {
    this->location_ = new two_dim::Point(x, y);
    this->speed_ = speed;
}
Tracked::~Tracked() {
    delete this->location_;
}

bool Tracked::CanTranslateTo(const Coordinate* goal) const {
    const two_dim::Point *end = dynamic_cast<const two_dim::Point *>(goal);
    const two_dim::Point *me = dynamic_cast<const two_dim::Point *>(this->location_);

    double xDif = (end->x() - me->x()) * (end->x() - me->x());
    double yDif = (end->y() - me->y()) * (end->y() - me->y());
    return this->speed() >= sqrt(xDif+yDif);
}
void Tracked::Translate(const Offset* direction) {
    two_dim::Point *point = dynamic_cast<two_dim::Point *>(this->location_);
    point->AddOffset(direction);
}
}  // namespace csce240

