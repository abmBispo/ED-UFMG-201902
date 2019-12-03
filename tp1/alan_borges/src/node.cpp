#include "../includes/node.hpp"

// Constructors
Node::Node() {
  this->next_node = nullptr;
  this->previous_node = nullptr;
  this->mililiters = 0;
  this->count_operations = 1;
};

Node::Node(Node *next_node, Node *previous_node) {
  this->next_node = next_node;
  this->previous_node = previous_node;
  this->mililiters = 0;
  this->count_operations = 1;
};

Node::Node(Node *next_node, Node *previous_node, int mililiters) {
  this->next_node = next_node;
  this->previous_node = previous_node;
  this->mililiters = mililiters;
  this->count_operations = 1;
};

Node::Node(Node *next_node, Node *previous_node, int mililiters, int count_operations) {
  this->next_node = next_node;
  this->previous_node = previous_node;
  this->mililiters = mililiters;
  this->count_operations = count_operations;
};

// Getters & Setters
Node* Node::get_next_node() {
  return this->next_node;
}

void Node::set_next_node(Node *node) {
  this->next_node = node;
}

Node* Node::get_previous_node() {
  return this->previous_node;
}

void Node::set_previous_node(Node *node) {
  this->previous_node = node;
}

int Node::get_mililiters() {
  return this->mililiters;
}

int Node::get_count_operations() {
  return this->count_operations;
}

bool Node::is_content_node() {
  return this->next_node != nullptr && this->previous_node != nullptr;
}
