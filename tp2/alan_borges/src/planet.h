#include <string>
#ifndef __PLANET__
#define __PLANET__
class Planet {
private:
  std::string name;
  int time_spent;

public:
  Planet();
  ~Planet();

  void set_values(std::string name, int time_spent);
  std::string get_name();
  int get_time_spent();
};
#endif
