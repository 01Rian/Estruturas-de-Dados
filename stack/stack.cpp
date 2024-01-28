#include <iostream>
#include "stack.h"

using namespace std;

stack::stack() {
  size = 0;
  structure = new TypeItem[MAX_ITENS];
}

stack::~stack() {
  delete [] structure;
}

bool stack::isFull() {
  return (size == MAX_ITENS);
}

bool stack::isEmpty() {
  return (size == 0);
}

void stack::push(TypeItem item) {
  if (isFull()) {
    cout << "Stack is full\n";
  } else {
    structure[size] = item;
    size++;
  }
}

TypeItem stack::pop() {
  if (isEmpty()) {
    cout << "Stack is empty\n";
    return 0;
  } else {
    size--;
    return structure[size];
  }
}

void stack::print() {
  cout << "Stack: [ ";
  for (int i = 0; i < size; i++) {
    cout << structure[i] << " ";
  }
  cout << " ]\n";
}

int stack::lenght() {
  return size;
}