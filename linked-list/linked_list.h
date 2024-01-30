typedef int TypeItem;

// Dynamic stack using linked list
struct Node {
  TypeItem value;
  Node* next;
};

class linked_list {
  private:
  Node* node;

  public:
  linked_list();
  ~linked_list();
  bool isEmpty();
  bool isFull();
  void push(TypeItem item);
  TypeItem pop();
  void print();
};