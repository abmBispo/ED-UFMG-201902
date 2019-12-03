#include <iostream>
#include <cstdio>
#include "../includes/list.hpp"

int main() {
  int q;
  char e;
  List bottles;

  while(scanf("%d %c", &q, &e) != EOF) {
    if (e == 'p') {
      std::cout << bottles.find_solution(q) << std::endl;
    } else if (e == 'i') {
      // Entrada do tipo i: inclui
      bottles.insert(q);
    } else if (e == 'r') {
      // Entrada do tipo r: remove
      bottles.remove(q);
    }
  }

  bottles.clean();
  return 0;
}
