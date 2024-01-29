#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {

  queue queue1;
  int option;
  TypeItem item;
  cout << "Program queue:\n";

  do {
    cout << "Digit 0 for stop\n";
    cout << "Digit 1 for add element\n";
    cout << "Digit 2 for remove element\n";
    cout << "Digit 3 for print queue\n";
    cin >> option;

    if (option == 1) {
      cout << "Element for add:\n"; 
      cin >> item;
      queue1.push(item);
    } else if (option == 2) {
      item = queue1.pop();
      cout << "Element remove: " << item << endl;
    } else if (option == 3) {
      queue1.print();
    }

  } while(option != 0);
  
  return 0;
}