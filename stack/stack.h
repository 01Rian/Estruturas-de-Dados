typedef int TypeItem;
const int MAX_ITENS = 100;

class stack {

  private:
  int size;
  TypeItem* structure;

  public:
  stack();
  ~stack();
  bool isFull();
  bool isEmpty();
  void push(TypeItem item);
  TypeItem pop();
  void print();
  int lenght();

};