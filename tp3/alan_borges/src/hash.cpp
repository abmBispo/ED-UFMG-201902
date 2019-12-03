#include "hash.h"
Hash::Hash() {};
Hash::~Hash() {};

LinkedList Hash::get_list() {
  return this->list;
}

void Hash::operator<<(std::string word) {
  this->list.insert(word);
}
