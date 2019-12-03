#ifndef __NODE__
#define __NODE__
#include "planet.h"

class Node {
  private:
    Planet planet;
    Node *next_node;

  public:
    Node(Planet planet);
    Node* get_next_node();
    Planet get_planet();
    void set_next_node(Node *new_node);
};

#endif
