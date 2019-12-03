#include "utils.h"
#include "planet.h"
#include "month_bucket.h"
#include "agenda.h"
#include "queue.h"
#include <string>
#include <iostream>

int main() {
  int monthly_time_to_visitation;
  int planet_count;
  int planet_name_char_count;

  std::cin >> monthly_time_to_visitation >> planet_count >> planet_name_char_count;

  int planet_time_spent;
  std::string planet_name;
  Planet *planets = new Planet[planet_count];

  for (int i = 0; i < planet_count; i++) {
    std::cin >> planet_time_spent >> planet_name;
    planets[i].set_values(planet_name, planet_time_spent);
  }

  // O(n * log n)
  Utils::merge_sort(planets, 0, planet_count - 1);

  // Creating Agenda list to keep the months
  Agenda *agenda = new Agenda(planet_count);
  MonthBucket *initial_month_bucket = new MonthBucket;
  agenda->insert(initial_month_bucket);

  int aux_max_monthly_time = monthly_time_to_visitation;
  int end = 0, begin = 0;

  for (int i = 0; i < planet_count; i++) {
    if (aux_max_monthly_time - planets[i].get_time_spent() >= 0) {
      aux_max_monthly_time -= planets[i].get_time_spent();
      end++;
    } else {
      Utils::radix_sort(planets + begin, planet_name_char_count, end);
      agenda->get_last_month()->set_planets(planets + begin, end);
      MonthBucket *month_bucket = new MonthBucket;
      agenda->insert(month_bucket);
      end = 1;
      begin = i;
      aux_max_monthly_time = monthly_time_to_visitation - planets[i].get_time_spent();
    }
  }

  // Adding planets to last month
  Utils::radix_sort(planets + begin, planet_name_char_count, planet_count - begin);
  agenda->get_last_month()->set_planets(planets + begin, planet_count - begin);

  agenda->inspect();
  return 0;
}
