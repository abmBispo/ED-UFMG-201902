#include "node.h"

Node::Node(Planet planet) {
  this->planet = planet;
}

Node* Node::get_next_node() {
  return this->next_node;
}

Planet Node::get_planet() {
  return this->planet;
}

void Node::set_next_node(Node *new_node) {
  this->next_node = new_node;
}
