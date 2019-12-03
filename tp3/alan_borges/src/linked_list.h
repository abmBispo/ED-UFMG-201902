#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include "node.h"
#include <string>
#include <iostream>

class LinkedList {
private:
  int length;
  Node *head;

public:
  LinkedList();
  ~LinkedList();
  Node *get_head();
  int get_length();
  int get_word_count(std::string word);
  void insert(std::string word);
  void describe();
};

#endif
