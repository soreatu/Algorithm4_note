// Quene ADT implemented by linked-list

template<typename Item>
class Quene {
  private:
	// representation of node	
	struct Node{
		Item item;
		Node *next;
	};
	Node *first; // first node (least recently added)
	Node *last; // last node (most recently added)
	int N; // number of items

  public:
	// constructor
	Quene() { first = nullptr; last = nullptr; N=0; }
	// destructor
	~Quene();

	// return whethe the quene is empty
	bool isEmpty() { return N == 0; }
	// return size of the quene
	int size() { return N; }
	// add an item to the end of the quene
	void enquene(Item item);
	// delete an item at the beginning of the quene
	Item dequene();
};


template<typename Item>
Quene<Item>::~Quene() {
	while(first!=nullptr){
		Node *oldfirst = first;
		first = first->next;
		delete oldfirst;
		N--;
	}
}

template<typename Item>
void Quene<Item>::enquene(Item item) {
	Node *oldlast = last;
	last = new Node();
	last->item = item;
	last->next = nullptr;
	if(isEmpty())
		first = last;
	else
		oldlast->next = last;
	N++;
}

template<typename Item>
Item Quene<Item>::dequene() {
	// process exception
	if(isEmpty())
		throw "Quene is empty, cannot dequene any more!"

	Item item = first->item;
	Node *oldfirst = first;
	first = first->next;
	delete oldfirst;
	N--;
	if(isEmpty())
		last = nullptr;
	return item;
}