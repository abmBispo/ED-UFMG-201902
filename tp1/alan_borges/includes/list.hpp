#ifndef __BOTTLE__
#define __BOTTLE__
#include "../includes/node.hpp"
#include <cstdio>
#include <iostream>

class List {
  private:
    Node *head;
    Node *tail;

  public:
    List();
    void insert(int mililiters);
    void insert(int mililiters, int count_operations);
    void remove(int mililiters);
    void inspect();
    void reverse_inspect();
    int find_solution(int mililiters);
    Node* get_first_node();
    Node* remove_front();
    void clean();
};

#endif
