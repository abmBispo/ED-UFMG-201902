#ifndef __HASH__
#define __HASH__
#include <string>
#include "linked_list.h"
class Hash {
private:
  LinkedList list;
public:
  Hash();
  ~Hash();
  LinkedList get_list();
  void operator<<(std::string word);
};
#endif
