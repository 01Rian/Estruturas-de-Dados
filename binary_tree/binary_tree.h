#include <iostream>
#include "student.cpp"

struct Node
{
  Student student;
  Node* left_child;
  Node* right_child;
};

class Binary_tree
{

private:
  Node* root;

public:
  Binary_tree();
  ~Binary_tree();
  void delete_tree(Node* n_current);
  Node* get_root();
  bool isEmpty();
  bool isFull();
  void insert(Student s);
  void remove(Student s);
  void remove_search(Student s, Node*& n_current);
  void delete_node(Node*& n_current);
  void get_successor(Student& s, Node* temp);
  void search(Student& s, bool& search);
  void print_preorder(Node* n_current);
  void print_inorder(Node* n_current);
  void print_postorder(Node* n_current);
};
