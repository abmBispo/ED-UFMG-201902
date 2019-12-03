#include "linked_list.h"

LinkedList::~LinkedList() {}

LinkedList::LinkedList() {
  this->head = nullptr;
  this->length = 0;
}

void LinkedList::insert(std::string word) {
  Node *new_node = new Node(word);
  if (this->head == nullptr) {
    this->head = new_node;
  } else {
    Node *aux_node = this->head;
    while (aux_node->get_next_node() != nullptr) {
      aux_node = aux_node->get_next_node();
    }
    aux_node->set_next_node(new_node);
  }
  this->length++;
}

Node* LinkedList::get_head() {
  return this->head;
}

int LinkedList::get_length() {
  return this->length;
}

int LinkedList::get_word_count(std::string word) {
  int word_count = 0;
  Node *aux_node = this->head;
  while (aux_node != nullptr) {
    if (word == aux_node->get_word()) word_count++;
    aux_node = aux_node->get_next_node();
  }
  return word_count;
}

void LinkedList::describe() {
  Node *aux_node = this->head;
  while (aux_node != nullptr) {
    std::cout << aux_node->get_word() << " -> ";
    aux_node = aux_node->get_next_node();
  }
}
