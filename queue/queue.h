typedef int TypeItem;
const int MAX_ITENS = 100;

class queue
{
private:
  int first, last;
  TypeItem *structure;

public:
  queue();
  ~queue();
  bool isEmpty();
  bool isFull();
  void push(TypeItem item);
  TypeItem pop();
  void print();
};