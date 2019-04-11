// Doubly-linked list ADT

template<typename Item>
class DoubleLinkedList {
  private:
    // representation of node
	struct DoubleNode
	{
		Item item;
		DoubleNode *forward;
		DoubleNode *next;
	};
	DoubleNode *first; // item at the beginning of the list
	DoubleNode *last; // item at the end of the list
	int N; // numbers of the items
	// find the specified item in the list
	DoubleNode *findItem(Item item);
	
  public:
	// constructor
	DoubleLinkedList();
	// destructor
	~DoubleLinkedList();

	// return whether the list is empty
	bool isEmpty() { return N == 0; }
	// return size of the list
	int Size() { return N; }
	// push an item at the beginning of the list
	void push_front(Item item);
	// push an item at the end of the list
	void push_back(Item item);
	// pop an item at the beginning of the list
	Item pop_front();
	// pop an item at the end of the list
	Item pop_back();
	// insert an item before the specified location
	void Insert_before(Item item, Item loaction);
	// insert an item after the specified location
	void Insert_after(Item item, Item loaction);
	// remove a specified item
	bool remove(Item item);
};


template<typename Item> // the function header here is a little tricky
typename DoubleLinkedList<Item>::DoubleNode * DoubleLinkedList<Item>::findItem(Item item) {
	DoubleNode *current = first;
	while(current!=nullptr){
		if(current->item == item)
			break;
		current = current->next;
	}
	return current;
}

template<typename Item>
DoubleLinkedList<Item>::DoubleLinkedList() {
	first = nullptr;
	last = nullptr;
	N = 0;
}

template<typename Item>
DoubleLinkedList<Item>::~DoubleLinkedList() {
	while(first!=nullptr){
		DoubleNode *oldfirst = first;
		first = first->next;
		delete first;
		N--;
	}
}


template<typename Item>
void DoubleLinkedList<Item>::push_front(Item item) {
	DoubleNode *oldfirst = first;
	first = new DoubleNode();
	first->item = item;
	first->forward = nullptr;
	if(isEmpty()){
		first->next = nullptr;
		last = first;
	}
	else{
		first->next = oldfirst;
		oldfirst->forward = first;
	}
	N++;
}

template<typename Item>
void DoubleLinkedList<Item>::push_back(Item item) {
	DoubleNode *oldlast = last;
	last = new DoubleNode();
	last->item = item;
	last->next = nullptr;
	if(isEmpty()){
		first = last;
		last->forward = nullptr;
	}
	else{
		last->forward = oldlast;
		oldlast->next = last;
	}
	N++;
}

template<typename Item>
Item DoubleLinkedList<Item>::pop_front() {
	DoubleNode *oldfirst = first;
	Item item = first->item;
	first = first->next;
	N--;
	if(isEmpty())
		last = nullptr;
	else
		first->forward = nullptr;
	delete oldfirst;
	return item;
}

template<typename Item>
Item DoubleLinkedList<Item>::pop_back() {
	DoubleNode *oldlast = last;
	Item item = last->item;
	last = last->forward;
	N--;
	if(isEmpty())
		first = nullptr;
	else
		last->next = nullptr;
	delete oldlast;
	return item;
}

template<typename Item>
void DoubleLinkedList<Item>::Insert_before(Item item, Item location) {
	DoubleNode *find = findItem(location);
	if(find == nullptr)
		return; // need processing
	DoubleNode *before = find->forward;
	DoubleNode *newNode = new DoubleNode();
	newNode->item = item;
	newNode->forward = before;
	newNode->next = find;
	if(find == first)
		first = newNode;
	else
		before->next = newNode;
	find->forward = newNode;
}

template<typename Item>
void DoubleLinkedList<Item>::Insert_after(Item item, Item loaction) {
	DoubleNode *find = findItem(loaction);
	if(find==nullptr)
		return; // ditto
	DoubleNode *after = find->next;
	DoubleNode *newNode = new DoubleNode();
	newNode->item = item;
	newNode->forward = find;
	newNode->next = after;
	if(find == last)
		last = newNode;
	else
		after->forward = newNode;
	find->next = newNode;
}

template<typename Item>
bool DoubleLinkedList<Item>::remove(Item item) {
	DoubleNode *find = findItem(item);
	if(find == nullptr)
		return false;
	if(find == first)
		first = find->next;
	else
		find->forward->next = find->next;
	if(find == last)
		last = find->forward;
	else
		find->next->forward = find->forward;
	delete find;
	N--;
	return true;
}