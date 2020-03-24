#include <bits/stdc++.h>
#include "linkedList.h"

using namespace std;



	linkedList::linkedList(): first {NULL}
	{
	}

	int linkedList::size()
	{
		int sum = 0;
		node* elem = first;
		while((*elem).next != NULL){
			sum++;
			elem = (*elem).next;
		}
		return sum;
	}

	bool linkedList::empty()
	{
		return first == NULL;
	}

	int linkedList::value_at(int i)
	{
		node* elem = first;
		while(i--){
			elem = (*elem).next;
		}
		return (*elem).value;
	}

	void linkedList::push_front(int elem)
	{
		node newNode;
		newNode.next = first;
		newNode.value = elem;
		first = &newNode;
	}

	int linkedList::pop_front()
	{
		node* node = first;
		int value = (*first).value;
		first = (*first).next;
		delete node;
		return value;
	}
	
	void linkedList::push_back(int value)
	{
		node* prev = first;
		node* actual = first;
		while((*actual).next != NULL){
			prev = actual;
			actual = (*actual).next;
		}
		node newNode;
		newNode.next = NULL;
		newNode.value = value;
		(*prev).next = &newNode;

	}

 	int linkedList::pop_back()
 	{
 		node* newLast = first;
 		node* prev = first;
		node* actual = first;
		while((*actual).next != NULL){
			newLast = prev;
			prev = actual;
			actual = (*actual).next;
		}
		(*newLast).next = NULL;
		int value = (*prev).value;
		delete prev;
		return value;
 	}

 	int linkedList::front()
 	{
 		return (*first).value;
 	}

 	int linkedList::back(){
 		int numberOfElems = (*this).size();
 		return (*this).value_at(numberOfElems);
 	}

 	void linkedList::insert(int index, int value)
 	{
 		node* prev = first;
		node* actual = first;
		while(index--){
			prev = actual;
			actual = (*actual).next;
		}
		node newNode;
		newNode.next = actual;
		newNode.value = value;
		(*prev).next = &newNode;
 	}

 	void linkedList::erase(int index)
 	{
 		node* prev = first;
		node* actual = first;
		while(index--){
			prev = actual;
			actual = (*actual).next;
		}
		(*prev).next = (*actual).next;
		delete actual;
 	}
 	int linkedList::value_n_from_end(int n)
 	{
 		int index = (*this).size();
 		index -= n;
 		return (*this).value_at(index);
 	}
 	void linkedList::reverse()
 	{
 		node* actual = first;
 		node* foward = (*actual).next;
 		node* temp;
 		(*actual).next = NULL;
 		while((*foward).next != NULL){
 			temp = (*foward).next;
 			(*foward).next = actual;
 			actual = foward;
 			foward = temp;
 		}
 		(*foward).next = actual;
 		first = foward;
 	}

 	void linkedList::remove_value(int value){
 		node* prev = first;
 		node* node = first;
 		
 		while((*node).value != value){
 			prev = node;
 			node = (*node).next;
 		}
 		prev = (*node).next;
 		delete node;
 	}

 	void linkedList::printList()
 	{
 		if(first == NULL){
 			cout << "The list is empty"
 		}else{
 			node* it = first;
 			while((*it).next != NULL){
 				cout << (*it).value  << " -> ";
 				it = (*it).next;
 			}
 			cout << (*it).value << " *-* End of list *-*"
 		}
 	}













//---------------------main-------------------------//

int main() {


	return 0;
}
























