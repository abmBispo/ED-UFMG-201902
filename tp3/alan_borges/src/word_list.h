#ifndef __WORD_LIST__
#define __WORD_LIST__
#include <string>
#include <iostream>
#include "word.h"
class WordList {
private:
  Word *head;
  int length;
public:
  WordList();
  ~WordList();
  Word *get_head();
  int get_length();
  void insert(Word *word);
  void remove(Word *word);
  void describe();
};
#endif
