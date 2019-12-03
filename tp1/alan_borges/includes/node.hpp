#ifndef __NODE__
#define __NODE__

class Node {
  private:
    int count_operations;
    int mililiters;
    Node *next_node;
    Node *previous_node;

  public:
    Node();
    Node(Node *next_node, Node *previous_node);
    Node(Node *next_node, Node *previous_node, int mililiters);
    Node(Node *next_node, Node *previous_node, int mililiters, int count_operations);
    Node* get_next_node();
    void set_next_node(Node *node);
    Node* get_previous_node();
    void set_previous_node(Node *node);
    int get_mililiters();
    int get_count_operations();
    bool is_content_node();
};

#endif
