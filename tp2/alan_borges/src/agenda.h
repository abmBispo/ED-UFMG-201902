#ifndef __AGENDA__
#define __AGENDA__

#include "month_bucket.h"
#include <iostream>

class Agenda {
private:
  MonthBucket *head;
  MonthBucket *tail;
  int planet_count;

public:
  Agenda(int planet_count);
  ~Agenda();
  void insert(MonthBucket new_month_bucket);
  MonthBucket* get_last_month();
  void insert(MonthBucket *new_month_bucket);
  void inspect();
};

#endif
