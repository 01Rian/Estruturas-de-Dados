#include <iostream>
#include "student.cpp"

class Hash
{
private:
  int hashFunction(Student student);
  int max_itens;
  int max_positions;
  int qty_itens;
  Student *structure;

public:
  Hash(int array_size, int max);
  ~Hash();
  bool isFull();
  int getSize();
  void insert(Student student);
  void remove(Student student);
  void search(Student &student, bool &search);
  void print();
};