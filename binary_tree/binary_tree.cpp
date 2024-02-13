#include <iostream>
#include <cstddef>
#include "binary_tree.h"

using namespace std;

Binary_tree::Binary_tree()
{
  root = NULL;
}

Binary_tree::~Binary_tree()
{
  delete_tree(root);
}

void Binary_tree::delete_tree(Node *n_current)
{
  if (n_current != NULL)
  {
    delete_tree(n_current->left_child);
    delete_tree(n_current->right_child);

    delete n_current;
  }
}

Node *Binary_tree::get_root()
{
  return root;
}

bool Binary_tree::isEmpty()
{
  return root == NULL;
}

bool Binary_tree::isFull()
{
  try
  {
    Node *temp = new Node();
    delete temp;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void Binary_tree::insert(Student s)
{
  if (isFull())
  {
    cout << "A Arvore esta cheia!\n";
    cout << "Nao foi possivel inserir este elemento!\n";
  }
  else
  {
    Node *newNode = new Node;
    newNode->student = s;
    newNode->left_child = NULL;
    newNode->right_child = NULL;

    if (root == NULL)
    {
      root = newNode;
    }
    else
    {
      Node *temp = root;

      while (temp != NULL)
      {
        if (s.getRa() < temp->student.getRa())
        {
          if (temp->left_child == NULL)
          {
            temp->left_child = newNode;
            break;
          }
          else
          {
            temp = temp->left_child;
          }
        }
        else
        {
          if (temp->right_child == NULL)
          {
            temp->right_child = newNode;
            break;
          }
          else
          {
            temp = temp->right_child;
          }
        }
      }
    }
  }
}

void Binary_tree::remove(Student s)
{
  remove_search(s, root);
}

void Binary_tree::remove_search(Student s, Node *&n_current)
{
  if (s.getRa() < n_current->student.getRa())
  {
    remove_search(s, n_current->left_child);
  }
  else if (s.getRa() > n_current->student.getRa())
  {
    remove_search(s, n_current->right_child);
  }
  else
  {
    delete_node(n_current);
  }
}

void Binary_tree::delete_node(Node *&n_current)
{
  Node *temp = n_current;

  if (n_current->left_child == NULL)
  {
    n_current = n_current->right_child;
    delete temp;
  }
  else if (n_current->right_child == NULL)
  {
    n_current = n_current->left_child;
    delete temp;
  }
  else
  {
    Student successor;
    get_successor(successor, n_current);
    n_current->student = successor;
    remove_search(successor, n_current->right_child);
  }
}

void Binary_tree::get_successor(Student &s, Node *temp)
{
  temp = temp->right_child;
  while (temp->left_child != NULL)
  {
    temp = temp->left_child;
  }
  s = temp->student;
}

void Binary_tree::search(Student &s, bool &search)
{
  search = false;
  Node *current_node = root;

  while (current_node != NULL)
  {
    if (s.getRa() < current_node->student.getRa())
    {
      current_node = current_node->left_child;
    }
    else if (s.getRa() > current_node->student.getRa())
    {
      current_node = current_node->right_child;
    }
    else
    {
      search = true;
      s = current_node->student;
      break;
    }
  }
}

void Binary_tree::print_preorder(Node *n_current)
{
  if (n_current != NULL)
  {
    cout << n_current->student.getName() << ": ";
    cout << n_current->student.getRa() << endl;

    print_preorder(n_current->left_child);
    print_preorder(n_current->right_child);
  }
}

void Binary_tree::print_inorder(Node *n_current)
{
  if (n_current != NULL)
  {
    print_inorder(n_current->left_child);

    cout << n_current->student.getName() << ": ";
    cout << n_current->student.getRa() << endl;

    print_inorder(n_current->right_child);
  }
}

void Binary_tree::print_postorder(Node *n_current)
{
  if (n_current != NULL)
  {
    print_postorder(n_current->left_child);
    print_postorder(n_current->right_child);

    cout << n_current->student.getName() << ": ";
    cout << n_current->student.getRa() << endl;
  }
}