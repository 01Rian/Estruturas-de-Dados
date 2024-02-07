#include <iostream>
#include "linked_list.h"
#include <cstddef> // NULL

// Dynamic stack using linked list
using namespace std;

linked_list::linked_list()
{
  node = NULL;
}

linked_list::~linked_list()
{
  Node *nodeTemp;

  while (nodeTemp != NULL)
  {
    nodeTemp = node;
    node = node->next;
    delete nodeTemp;
  }
}

bool linked_list::isEmpty()
{
  return (node == NULL);
}

bool linked_list::isFull()
{
  Node *newNode;

  try
  {
    newNode = new Node;
    delete newNode;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void linked_list::push(TypeItem item)
{
  if (isFull())
  {
    cout << "Stack is full\n";
  }
  else
  {
    Node *newNode = new Node;
    newNode->value = item;
    newNode->next = node;
    node = newNode;
  }
}

TypeItem linked_list::pop()
{
  if (isEmpty())
  {
    cout << "Stack is empty\n";
    return 0;
  }
  else
  {
    Node *nodeTemp;
    nodeTemp = node;
    TypeItem item = node->value;
    node = node->next;
    delete nodeTemp;
    return item;
  }
}

void linked_list::print()
{
  Node *nodeTemp = node;
  cout << "Stack: [ ";
  while (nodeTemp != NULL)
  {
    cout << nodeTemp->value << " ";
    nodeTemp = nodeTemp->next;
  }
  cout << "]\n";
}