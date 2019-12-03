#include "agenda.h"

Agenda::Agenda(int planet_count){
  this->head = new MonthBucket;
  this->tail = new MonthBucket;
  this->head->set_next_month(this->tail);
  this->tail->set_previous_month(this->head);
  this->planet_count = planet_count;
}

Agenda::~Agenda(){}

void Agenda::insert(MonthBucket *new_month_bucket){
  new_month_bucket->set_next_month(this->tail);
  new_month_bucket->set_previous_month(this->tail->get_previous_month());
  this->tail->get_previous_month()->set_next_month(new_month_bucket);
  this->tail->set_previous_month(new_month_bucket);
}

MonthBucket* Agenda::get_last_month(){
  return this->tail->get_previous_month();
}

void Agenda::inspect() {
  MonthBucket *aux = this->head->get_next_month();
  int i = 1;
  while (aux->is_content_bucket()) {
    // Getting planets for the spefic month
    Planet *planets = aux->get_planets();
    for (int j = 0; j < aux->get_length(); j++) {
      std::cout << i << " " << planets[j].get_name() << " " << planets[j].get_time_spent() << std::endl;
    }
    // Iterating over months list
    aux = aux->get_next_month();
    i++;
  }
}
