#ifndef __QUEUE__
#define __QUEUE__
#include "node.h"
#include "planet.h"

class Queue {
private:
  Node *head;
  Node *tail;
  int size;

public:
  Queue();
  void add(Planet planet);
  Planet dequeue();
  int get_size();
};
#endif
