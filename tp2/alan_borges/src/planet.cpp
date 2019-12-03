#include "planet.h"

Planet::Planet() {
  this->name = "";
  this->time_spent = 0;
}

Planet::~Planet() {}

void Planet::set_values(std::string name, int time_spent) {
  this->name = name;
  this->time_spent = time_spent;
}

std::string Planet::get_name() {
  return this->name;
}

int Planet::get_time_spent(){
  return this->time_spent;
}
