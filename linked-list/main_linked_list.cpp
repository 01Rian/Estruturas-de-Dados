#include <iostream>
#include "linked_list.cpp"

using namespace std;

int main() {

  linked_list linked_list1;
  TypeItem item;
  int option;

  cout << "Loading stack:\n";

  do {
    cout << "Digit 0 for stop\n";
    cout << "Digit 1 for add element\n";
    cout << "Digit 2 for remove element\n";
    cout << "Digit 3 for print stack\n";
    cin >> option;

    if (option == 1) {
      cout << "Element for add:\n"; 
      cin >> item;
      linked_list1.push(item);
    } else if (option == 2) {
      item = linked_list1.pop();
      cout << "Element remove: " << item << endl;
    } else if (option == 3) {
      linked_list1.print();
    }

  } while(option != 0);

  return 0;
}