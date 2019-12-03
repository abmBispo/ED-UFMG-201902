#include "month_bucket.h"

MonthBucket::MonthBucket() {}

MonthBucket::~MonthBucket() {}

void MonthBucket::set_planets(Planet *planets, int length) {
  this->planets = planets;
  this->length = length;
}

Planet* MonthBucket::get_planets() {
  return this->planets;
}

MonthBucket* MonthBucket::get_previous_month() {
  return this->previous_bucket;
}

MonthBucket* MonthBucket::get_next_month() {
  return this->next_bucket;
}

int MonthBucket::get_length() {
  return this->length;
}

void MonthBucket::set_previous_month(MonthBucket *new_month_bucket) {
  this->previous_bucket = new_month_bucket;
}

void MonthBucket::set_next_month(MonthBucket *new_month_bucket) {
  this->next_bucket = new_month_bucket;
}

bool MonthBucket::is_content_bucket() {
  return this->next_bucket != nullptr && this->previous_bucket != nullptr;
}
