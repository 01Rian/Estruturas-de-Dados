#include <iostream>
#include "hash.cpp"

using namespace std;

int main()
{
  cout << "Programa gerador de Hash!\n";
  int array_size, max;
  cout << "Digite o tamanho da Hash!\n";
  cin >> array_size;
  cout << "Digite o numero maximo de elementos!\n";
  cin >> max;
  cout << "O fator de carga e: " << (float)max / (float)array_size << endl;

  Hash student_hash(array_size, max);
  int option;
  int ra;
  string name;
  bool search;

  do
  {
    cout << "Digite 0 para parar o algoritmo!\n";
    cout << "Digite 1 para inserir um elemento!\n";
    cout << "Digite 2 para remover um elemento!\n";
    cout << "Digite 3 para busca um elemento!\n";
    cout << "Digite 4 para imprimir a Hash!\n";
    cin >> option;

    if (option == 1)
    {
      cout << "Qual e o RA do aluno?\n";
      cin >> ra;
      cout << "Qual e o nome do aluno?\n";
      cin >> name;
      Student student(ra, name);
      student_hash.insert(student);
    }
    else if (option == 2)
    {
      cout << "Qual e o RA do aluno a ser removido?\n";
      cin >> ra;
      Student student(ra, " ");
      student_hash.remove(student);
    }
    else if (option == 3)
    {
      cout << "Qual e o RA do aluno a ser buscado?\n";
      cin >> ra;
      Student student(ra, " ");
      student_hash.search(student, search);
      if (search)
      {
        cout << "Aluno encontrado:\n";
        cout << "RA: " << student.getRa() << endl;
        cout << "Nome: " << student.getName() << endl;
      }
      else
      {
        cout << "Aluno nao encontrado!\n";
      }
    }
    else if (option == 4)
    {
      student_hash.print();
    }

  } while (option != 0);

  return 0;
}