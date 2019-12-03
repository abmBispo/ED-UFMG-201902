#include "../includes/list.hpp"
#include <math.h>

// Constructor
List::List() {
  this->head = new Node();
  this->tail = new Node();
  this->head->set_next_node(this->tail);
  this->tail->set_previous_node(this->head);
}

void List::insert(int mililiters){
  if (mililiters < 0) return;
  Node *node = new Node(this->tail, this->tail->get_previous_node(), mililiters);
  this->tail->get_previous_node()->set_next_node(node);
  this->tail->set_previous_node(node);
}

void List::insert(int mililiters, int count_operations){
  if (mililiters < 0) return;
  Node *node = new Node(this->tail, this->tail->get_previous_node(), mililiters, count_operations);
  this->tail->get_previous_node()->set_next_node(node);
  this->tail->set_previous_node(node);
}

void List::remove(int mililiters){
  Node *aux = this->head->get_next_node();
  while (aux->is_content_node()) {
    if (aux->get_mililiters() == mililiters) {
      aux->get_previous_node()->set_next_node(aux->get_next_node());
      aux->get_next_node()->set_previous_node(aux->get_previous_node());
      delete aux;
    }
    aux = aux->get_next_node();
  }
}

Node* List::remove_front(){
  Node *aux = this->head->get_next_node();
  this->head->set_next_node(aux->get_next_node());
  aux->get_next_node()->set_previous_node(this->head);
  return aux;
}

void List::inspect() {
  Node *aux = this->head->get_next_node();
  std::cout << std::endl;
  std::cout << "head -> ";
  while (aux->is_content_node()) {
    std::cout << aux->get_mililiters() << " -> ";
    aux = aux->get_next_node();
  }
  std::cout << "tail";
  std::cout << std::endl;
}

void List::reverse_inspect() {
  Node *aux = this->tail->get_previous_node();
  std::cout << std::endl;
  std::cout << "tail -> ";
  while (aux->is_content_node()) {
    std::cout << aux->get_mililiters() << " -> ";
    aux = aux->get_previous_node();
  }
  std::cout << "head";
  std::cout << std::endl;
}

Node* List::get_first_node() {
  return this->head->get_next_node();
}

int List::find_solution(int mililiters) {
  List possibilities;
  Node *list_node = this->head->get_next_node();
  Node *possibility_node = possibilities.get_first_node();

  while (list_node->is_content_node()) {
    if (list_node->get_mililiters() == mililiters) return 1;
    possibilities.insert(list_node->get_mililiters());
    list_node = list_node->get_next_node();
  }

  while (true) {
    possibility_node = possibilities.remove_front();
    list_node = this->head->get_next_node();
    // std::cout << "Rodando" << std::endl;
    // possibilities.inspect();
    // this->inspect();
    while (list_node->is_content_node()) {
      // std::cout << "---------------------------------------" << std::endl;
      // std::cout << "Procurando: " << mililiters << std::endl;
      // std::cout << possibility_node->get_mililiters() << " + " << list_node->get_mililiters() << " = " << possibility_node->get_mililiters() + list_node->get_mililiters() << std::endl;
      // std::cout << possibility_node->get_mililiters() << " - " << list_node->get_mililiters() << " = " << possibility_node->get_mililiters() - list_node->get_mililiters() << std::endl;
      // std::cout << "---------------------------------------" << std::endl;
      if ((possibility_node->get_mililiters() + list_node->get_mililiters() == mililiters) || (possibility_node->get_mililiters() - list_node->get_mililiters() == mililiters))
        return possibility_node->get_count_operations() + 1;
      possibilities.insert(possibility_node->get_mililiters() - list_node->get_mililiters(), possibility_node->get_count_operations() + 1);
      possibilities.insert(possibility_node->get_mililiters() + list_node->get_mililiters(), possibility_node->get_count_operations() + 1);
      list_node = list_node->get_next_node();
    }
  }
}

void List::clean() {
  Node *aux = this->head->get_next_node();
  while (aux->is_content_node()) {
    Node *aux_2 = aux->get_next_node();
    this->remove(aux->get_mililiters());
    aux = aux_2;
  }
}
