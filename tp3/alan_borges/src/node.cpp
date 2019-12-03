#include "node.h"

Node::Node(std::string word) {
  this->word = word;
  this->next_node = nullptr;
}

Node* Node::get_next_node() {
  return this->next_node;
}

std::string Node::get_word() {
  return this->word;
}

void Node::set_next_node(Node *new_node) {
  this->next_node = new_node;
}
