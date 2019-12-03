#ifndef __NODE__
#define __NODE__
#include <string>

class Node {
  private:
    std::string word;
    Node *next_node;

  public:
    Node(std::string word);
    Node* get_next_node();
    std::string get_word();
    void set_next_node(Node *new_node);
};

#endif
