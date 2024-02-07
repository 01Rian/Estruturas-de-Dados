#include <iostream>
#include "queue.h"

using namespace std;

queue::queue()
{
  first = 0;
  last = 0;
  structure = new TypeItem[MAX_ITENS];
}

queue::~queue()
{
  delete[] structure;
}

bool queue::isEmpty()
{
  return (first == last);
}

bool queue::isFull()
{
  return (last - first == MAX_ITENS);
}

void queue::push(TypeItem item)
{
  if (isFull())
  {
    cout << "Queue is full\n";
  }
  else
  {
    structure[last % MAX_ITENS] = item;
    last++;
  }
}

TypeItem queue::pop()
{
  if (isEmpty())
  {
    cout << "Queue is empty\n";
    return 0;
  }
  else
  {
    first++;
    return structure[(first - 1) % MAX_ITENS];
  }
}

void queue::print()
{
  cout << "Queue: [ ";
  for (int i = first; i < last; i++)
  {
    cout << structure[i % MAX_ITENS] << " ";
  }
  cout << "]\n";
}