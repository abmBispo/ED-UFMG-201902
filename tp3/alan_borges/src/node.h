#ifndef __NODE__
#define __NODE__
#include <string>

class Node {
  private:
    int count;
    std::string word;
    std::string huffman_code;
    Node *next_node;

  public:
    Node(std::string word);
    Node* get_next_node();
    std::string get_word();
    int get_count();
    std::string get_huffman_code();
    void set_huffman_code(std::string huffman_code);
    void set_next_node(Node *new_node);
    void increment_count();
};

#endif
