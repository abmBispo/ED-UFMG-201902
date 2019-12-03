#include "queue.h"

Queue::Queue() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

void Queue::add(Planet planet) {
  Node *new_node = new Node(planet);
  if (size == 0) {
    this->head = new_node;
    this->tail = new_node;
  } else if (size > 0) {
    this->tail->set_next_node(new_node);
    this->tail = new_node;
  }
  this->size++;
}

Planet Queue::dequeue() {
  if (size > 0) {
    Node *aux_node = this->head;
    this->head = aux_node->get_next_node();
    this->size--;
    return aux_node->get_planet();
  } else {
    return Planet();
  }
}

int Queue::get_size() {
  return this->size;
}
