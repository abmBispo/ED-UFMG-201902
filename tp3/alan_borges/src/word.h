#ifndef __WORD__
#define __WORD__
#include <string>
#include "node.h"

// Perdão Álisson
class Word {
private:
  int word_count;
  int leaves_count;
  Node *node;

  Word *next_word;
  Word *left;
  Word *right;
public:
  Word(int count, Node *node);
  Word(Word *left, Word *right);
  ~Word();
  Word* get_next_word();
  void set_next_word(Word *new_word);
  Node* get_node();
  int get_leaves_count();
  int get_word_count();
  void generate_codes(std::string code);
};
#endif
