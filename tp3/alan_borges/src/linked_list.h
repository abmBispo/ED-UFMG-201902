#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include "node.h"
#include <string>
#include <iostream>
#include <cstring>

class LinkedList {
private:
  int length;
  Node *head;
  static bool compare_str(char *str1, char *str2);

public:
  LinkedList();
  ~LinkedList();
  Node *get_head();
  int get_length();
  int get_word_count(std::string word);
  std::string get_huffman_code(std::string word);
  void insert(std::string word);
  void describe();
};

#endif
