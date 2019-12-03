#include <cstdio>
#include <iostream>
#include "hash.h"
#include "linked_list.h"

int main() {
  int n;
  scanf("%d", &n);

  Hash *main_hash = new Hash[n];
  std::string word;
  std::string op;

  for (int i = 0; i < n; ++i) {
    std::cin >> word;
    int word_ascii_weigth = 0;
    for (int i = 0; i < ((int) word.length()); i++) word_ascii_weigth += (word[i] - 'a');
    main_hash[word_ascii_weigth % n] << word;
  }

  while (std::cin >> op >> word) {
    int word_ascii_weigth = 0;
    for (int i = 0; i < ((int) word.length()); i++) word_ascii_weigth += (word[i] - 'a');
    if (op == "q") std::cout << main_hash[word_ascii_weigth % n].get_list().get_word_count(word) << std::endl;
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
