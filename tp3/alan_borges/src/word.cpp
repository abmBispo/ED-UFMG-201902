#include "word.h"
Word::Word(int count, str::string word) {
  this->count = count;
  this->word = word;
};

Word::~Word() {};

LinkedList Word::get_word() {
  return this->word;
}

void Word::operator<<(std::string word) {
  this->word = word;
}
