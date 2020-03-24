//-----------------Data-Structure------------------------//

struct node
{
	node* next;
	int value;
};

class linkedList {
private:
	node* first;
	void printList();
public:
	linkedList();
	int size();
	bool empty();
	int value_at(int i);
	void push_front(int elem);
	int pop_front();
	void push_back(int value);
 	int pop_back();
 	int front();
 	int back(); 
 	void insert(int index, int value);
 	void erase(int index);
 	int value_n_from_end(int n);
 	void reverse();
 	void remove_value(int value);
};





