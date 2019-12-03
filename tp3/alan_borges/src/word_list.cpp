#include "word_list.h"
WordList::WordList() {
  this->head = nullptr;
  this->length = 0;
}
WordList::~WordList() {}

void WordList::insert(Word *word) {
  if (this->head == nullptr) {
    this->head = word;
  } else {
    Word *aux_word = this->head;
    while (aux_word->get_next_word() != nullptr) {
      aux_word = aux_word->get_next_word();
    }
    aux_word->set_next_word(word);
  }
  this->length++;
}

void WordList::remove(Word *word) {
  Word *previous_aux_word;
  for (Word *aux_word = this->head; aux_word != nullptr; aux_word = aux_word->get_next_word()) {
    if (aux_word == word) {
      previous_aux_word->set_next_word(aux_word->get_next_word());
      this->length--;
    }
    previous_aux_word = aux_word;
  }
}

void WordList::describe() {
  Word *aux_word = this->head;
  while (aux_word != nullptr) {
    std::cout << aux_word->get_node()->get_word() << "(" << aux_word->get_node()->get_count() << ")" << std::endl;
    aux_word = aux_word->get_next_word();
  }
}

Word* WordList::get_head() {
  return this->head;
}

int WordList::get_length() {
  return this->length;
}
