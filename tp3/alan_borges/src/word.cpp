#include <iostream>
#include "word.h"

Word::Word(int word_count, Node *node) {
  this->word_count = word_count;
  this->node = node;
  this->leaves_count = 1;
};

Word::Word(Word *left, Word *right) {
  this->word_count = left->get_word_count() + right->get_word_count();
  this->leaves_count = left->get_leaves_count() + right->get_leaves_count();
  this->node = left->get_node();
  this->left = left;
  this->right = right;
};

Word::~Word() {};

Word* Word::get_next_word() {
  return this->next_word;
}

void Word::set_next_word(Word *new_word) {
  this->next_word = new_word;
}

Node* Word::get_node() {
  return this->node;
}

int Word::get_word_count() {
  return this->word_count;
}

int Word::get_leaves_count() {
  return this->leaves_count;
}

void Word::generate_codes(std::string code) {
  std::cout << "Huffman Code:" << code << std::endl;
  if (this->left != nullptr && this->right != nullptr) {
    this->left->generate_codes(code.append((std::string) "0"));
    this->right->generate_codes(code.append((std::string) "1"));
    this->node->set_huffman_code(code);
  }
}
