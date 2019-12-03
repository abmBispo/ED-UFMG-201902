#include "node.h"

Node::Node(std::string word) {
  this->word = word;
  this->count = 1;
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

void Node::increment_count() {
  this->count++;
}

int Node::get_count() {
  return this->count;
}

std::string Node::get_huffman_code() {
  return this->huffman_code;
}

void Node::set_huffman_code(std::string huffman_code) {
  this->huffman_code = huffman_code;
}
