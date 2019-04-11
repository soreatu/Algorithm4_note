// Stack ADT implemented by linked-list

template<typename Item>
class Stack {
  private:
    // representation of node
    struct Node
    {
        Item item;
        Node *next;
    };
    Node *first; // top of stack
    int N; // number of items

  public:
    // constructor
    Stack() {  first = nullptr; N = 0;  }
    // destructor
    ~Stack();

    // return whether the stack is empty
    bool isEmpty() {  return N == 0;  }
    // return size of the stack
    int Size() {  return N;  }
    // push an item at the beginning of the stack
    void push(Item item);
    // pop an item at the beginning of the stack
    Item pop();
};


template<typename Item>
Stack<Item>::~Stack() {
    while(first!=nullptr){
		Node *oldfirst = first;
        first = first->next;
		delete oldfirst;
        N--;
    }
}

template<typename Item>
void Stack<Item>::push(Item item) {
    Node *oldfirst = first;
    first = new Node();
    first->item = item;
    first->next = oldfirst;
    N++;
}

template<typename Item>
Item Stack<Item>::pop() {
    // process exception
	if(isEmpty())
		throw "Stack is empty, cannot pop any more!"
    
	Item item = first->item;
    first = first->next;
    N--;
    return item;
}