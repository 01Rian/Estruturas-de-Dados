#include <iostream>
#include "hash.h"

using namespace std;

Hash::Hash(int array_size, int max)
{
  qty_itens = 0;
  max_itens = max;
  max_positions = array_size;
  structure = new Student[array_size];
}

Hash::~Hash()
{
  delete[] structure;
}

int Hash::hashFunction(Student student)
{
  return (student.getRa() % max_positions);
}

bool Hash::isFull()
{
  return (qty_itens == max_itens);
}

int Hash::getSize()
{
  return qty_itens;
}

void Hash::insert(Student student)
{
  int local = hashFunction(student);

  while (structure[local].getRa() > 0)
  {
    local = (local + 1) % max_positions;
  }
  structure[local] = student;
  qty_itens++;
}

void Hash::remove(Student student)
{
  int local = hashFunction(student);
  bool test = false;

  while (structure[local].getRa() != -1)
  {
    if (structure[local].getRa() == student.getRa())
    {
      cout << "Elemento Removido!\n";
      structure[local] = Student(-2, " ");
      qty_itens--;
      test = true;
      break;
    }
    local = (local + 1) % max_positions;
  }

  if (!test)
  {
    cout << "O elemento nao encontrado!\n";
    cout << "Nenhum elemento foi removido!\n";
  }
}

void Hash::search(Student &student, bool &search)
{
  int local = hashFunction(student);
  search = false;
  
  while (structure[local].getRa() != -1)
  {
    if (structure[local].getRa() == student.getRa())
    {
      search = true;
      student = structure[local];
      break;
    }
    local = (local + 1) % max_positions;
  }
}

void Hash::print()
{
  cout << "Hash Table:\n";
  for (int i = 0; i < max_positions; i++)
  {
    if (structure[i].getRa() > 0)
    {
      cout << i << ": " << structure[i].getRa() << " ";
      cout << structure[i].getName() << endl;
    }
  }
}