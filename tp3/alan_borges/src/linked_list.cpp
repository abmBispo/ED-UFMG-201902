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
    Node *previous = aux_node;
    do {
      if (LinkedList::compare_str((char*) aux_node->get_word().c_str(), (char*) word.c_str())) {
        aux_node->increment_count();
        return;
      } else {
        previous = aux_node;
        aux_node = aux_node->get_next_node();
      }
    } while (aux_node != nullptr);
    aux_node = previous;
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
    if (word == aux_node->get_word()) {
      return aux_node->get_count();
    } else {
      aux_node = aux_node->get_next_node();
    }
  }
  return word_count;
}

std::string LinkedList::get_huffman_code(std::string word) {
  std::string huffman_code = "";
  Node *aux_node = this->head;
  while (aux_node != nullptr) {
    if (word == aux_node->get_word()) {
      return aux_node->get_huffman_code();
    } else {
      aux_node = aux_node->get_next_node();
    }
  }
  return huffman_code;
}


void LinkedList::describe() {
  Node *aux_node = this->head;
  while (aux_node != nullptr) {
    std::cout << aux_node->get_word() << "(" << aux_node->get_count() << ")" << " -> ";
    aux_node = aux_node->get_next_node();
  }
}

bool LinkedList::compare_str(char *str1, char *str2) {
  for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) if (str1[i] != str2[i]) return false;
  return true;
}
