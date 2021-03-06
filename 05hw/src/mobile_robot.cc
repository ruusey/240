/*
 * Copyright 2018
 * Author: Robert Usey
 * 04/30/2018
 * Homework 05
 *
 */
#include "../include/mobile_robot.h"  //NOLINT
#include <iostream>        //NOLINT
#include <cassert>         //NOLINT
#include <vector>          //NOLINT
#include <set>             //NOLINT

// MAINTAIN STATIC UNORDERED SET OF ROBOT UUIDS
namespace csce240 {
static std::set<std::string> robots;
MobileRobot::MobileRobot(const Translation* translation,
                         const CartesianCoord* location) {
  // assert(speed >= 0.0);
  this->speed_ = 0.0;
  this->id_ = generateUUID();
  this->location_ = location->Clone();
  this->translation_ = translation;
  robots.insert(this->id_);
}
MobileRobot::MobileRobot(const Translation* translation,
                         const CartesianCoord* location, double speed) {
  assert(speed >= 0.0);
  this->speed_ = speed;
  this->id_ = generateUUID();
  this->location_ = location->Clone();
  this->translation_ = translation;
  robots.insert(this->id_);
}
MobileRobot::~MobileRobot() {
  robots.erase(this->id_);
}
double MobileRobot::speed() const {
  return speed_;
}

const std::string MobileRobot::id() const {
  return id_;
}
bool MobileRobot::id(const std::string& id) {
  if (IsUnique(id)) {
    // IF NEW UUID IS UNIQUE REMOVE THE OLD ONE FROM SET
    robots.erase(this->id_);
    // SET THE UUID
    this->id_ = id;
    // ADD NEW ID TO THE SET
    robots.insert(this->id_);
    return true;
  } else {
    return false;
  }
}

bool MobileRobot::IsUnique(const std::string& id) {
  return !(robots.find(id) != robots.end());
}
bool MobileRobot::CanTranslateTo(const CartesianCoord* goal) const {
  return translation_->CanTranslateTo(location_, speed_, goal);
}
void MobileRobot::Translate(const CartesianOffset* direction) {
  translation_->Translate(direction, speed_, location_);
}
void MobileRobot::location(CartesianCoord* location) const {
  if (CanTranslateTo(location)) {

  }

}
std::string MobileRobot::generateUUID() {
  const std::string CHARS =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  std::string uuid = std::string(36, ' ');
  int rnd = 0;
  int r = 0;

  uuid[8] = '-';
  uuid[13] = '-';
  uuid[18] = '-';
  uuid[23] = '-';

  uuid[14] = '4';

  for (int i = 0; i < 36; i++) {
    if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
      if (rnd <= 0x02) {
        rnd = 0x2000000 + (std::rand() * 0x1000000) | 0;
      }
      rnd >>= 4;
      uuid[i] = CHARS[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
    }
  }
  return uuid;
}
}  // namespace csce240

