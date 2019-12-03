#ifndef __MONTH_BUCKET__
#define __MONTH_BUCKET__
#include "planet.h"
#include <iostream>

class MonthBucket {
private:
  Planet *planets;
  int length;
  MonthBucket *previous_bucket;
  MonthBucket *next_bucket;

public:
  MonthBucket();
  ~MonthBucket();
  void set_planets(Planet *planets, int length);
  Planet* get_planets();
  MonthBucket *get_previous_month();
  MonthBucket *get_next_month();
  int get_length();
  void set_previous_month(MonthBucket *new_month_bucket);
  void set_next_month(MonthBucket *new_month_bucket);
  bool is_content_bucket();
};

#endif
