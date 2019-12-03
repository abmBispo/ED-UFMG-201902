#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "hash.h"
#include "linked_list.h"
#include "node.h"
#include "word.h"
#include "word_list.h"

bool compare(Word* a, Word* b){
  if(a->get_word_count() < b->get_word_count()){
    return true;
  }
  else if(a->get_leaves_count() < b->get_leaves_count()){
    return true;
  }
  else{
    for(int i = 0; a->get_node()->get_word()[i] != '\0' || b->get_node()->get_word()[i] != '\0'; i++){
      if(a->get_node()->get_word()[i] > b->get_node()->get_word()[i]){
        return true;
      }
    }
    return false;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  Hash *main_hash = new Hash[n];
  std::string word;
  std::string op;

  for (int i = 0; i < n; ++i) {
    std::cin >> word;
    int word_ascii_weigth = 0;
    for (int i = 0; i < ((int) word.length()); i++){
      word_ascii_weigth += (word[i] - 'a');
    }
    main_hash[word_ascii_weigth % n] << word;
  }

  WordList word_list;
  for (int i = 0; i < n; i++) {
    LinkedList aux_list = main_hash[i].get_list();
    for (Node* aux_node = aux_list.get_head(); aux_node != nullptr; aux_node = aux_node->get_next_node()) {
      Word *word = new Word(aux_node->get_count(), aux_node);
      word_list.insert(word);
    }
  }

  // word_list.describe();
  while (word_list.get_length() > 1) {
    Word *a = nullptr, *b = nullptr;

    for (Word *aux_word = word_list.get_head(); aux_word != nullptr; aux_word = aux_word->get_next_word()) {
      if(a == nullptr || compare(a, aux_word)){
        b = a;
        a = aux_word;
      }
      else if(b == nullptr || compare(b, aux_word)){
        b = aux_word;
      }
    }

    word_list.remove(a);
    word_list.remove(b);
    Word *new_word = new Word(a, b);
    word_list.insert(new_word);
  }

  Word *hf = word_list.get_head();
  hf->generate_codes("");
  std::cout << "Huffman Code: " << hf->get_node()->get_huffman_code() << std::endl;


  while (std::cin >> op >> word) {
    int word_ascii_weigth = 0;
    for (int i = 0; i < ((int) word.length()); i++) word_ascii_weigth += (word[i] - 'a');
    if (op == "q") std::cout << main_hash[word_ascii_weigth % n].get_list().get_word_count(word) << std::endl;
    if (op == "c") std::cout << main_hash[word_ascii_weigth % n].get_list().get_huffman_code(word) << std::endl;
  }


  // Describe list
  // std::cout << std::endl;
  // std::cout << std::endl;
  // for (int i = 0; i < n; i++) {
  //   std::cout << "Posição " << i << ": ";
  //   main_hash[i].get_list().describe();
  //   std::cout << std::endl;
  // }

  return 0;
}
