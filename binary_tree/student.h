#include <iostream>

using namespace std;

class Student
{
private:
  int ra;
  std::string name;

public:
  Student();
  Student(int r, std::string n);
  string getName();
  int getRa();
};
