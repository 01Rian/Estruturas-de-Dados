#include <iostream>
#include "binary_tree.cpp"

using namespace std;

int main()
{
  Binary_tree student_tree;
  int option, ra, imp;
  string name;
  bool search = false;

  do
  {
    cout << "Digite 0 para parar o algoritmo!\n";
    cout << "Digite 1 para inserir um elemento!\n";
    cout << "Digite 2 para remover um elemento!\n";
    cout << "Digite 3 para buscar um elemento!\n";
    cout << "Digite 4 para imprimir a arvore!\n";
    cin >> option;

    if (option == 1)
    {
      cout << "Digite o nome do aluno:\n";
      cin >> name;
      cout << "Digite o RA do aluno:\n";
      cin >> ra;

      Student student(ra, name);

      if (student_tree.isFull())
      {
        cout << "A Árvore esta cheia!\n";
        cout << "Nao foi possivel inserir o elemento!\n";
      }
      else
      {
        student_tree.insert(student);
      }
    }
    else if (option == 2)
    {
      cout << "Digite o RA do aluno a ser removido!\n";
      cin >> ra;

      Student student(ra, " ");
      student_tree.remove(student);

    }
    else if (option == 3)
    {
      cout << "Digite o RA do aluno a ser buscado!\n";
      cin >> ra;

      Student student(ra, " ");
      student_tree.search(student, search);
      
      if (search)
      {
        cout << "Elemento encontrado!\n";
        cout << "Nome: " << student.getName() << endl;
        cout << "RA: " << student.getRa() << endl;
      }
      else
      {
        cout << "Elemento nao encontrado!\n";
      }
    }
    else if (option == 4)
    {
      cout << "Digite 1 para fazer a impressao em pre ordem!\n";
      cout << "Digite 2 para fazer a impressao em ordem!\n";
      cout << "Digite 3 para fazer a impressao em pos ordem!\n";
      cin >> imp;
      
      if (imp == 1)
      {
        student_tree.print_preorder(student_tree.get_root());
      }
      else if (imp == 2)
      {
        student_tree.print_inorder(student_tree.get_root());
      }
      else
      {
        student_tree.print_postorder(student_tree.get_root());
      }
    }
  } while (option != 0);

  return 0;
}