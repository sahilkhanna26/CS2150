// Sahil Khanna (sk5xvh) List.cpp
#include <iostream>
#include <string>
using namespace std;

#include "List.h" 


//Default constructor
List::List(){
	count = 0;
	head = new ListNode();
	tail = new ListNode();
	head->next=tail;
    tail->previous=head;
	
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//Destructor
List::~List(){
	makeEmpty();
	delete head;
	delete tail;
}

//isEmpty method
bool List :: isEmpty() const{
	if (size() == 0){
		return 1;
	}
	return 0;
	
}

//makeEmpty
void List :: makeEmpty(){
	ListNode* curr = head->next;

	while (curr != tail){
		curr = curr -> next;
		delete curr -> previous;
	}

	count = 0;
	head -> next = tail;
	tail -> previous = head;

}

//first method
ListItr List :: first(){
	ListItr* y = new ListItr();

	y->current = head ->next;

	return *y;
}

//last method
 ListItr List:: last(){
 	ListItr*  z = new ListItr();
 	z->current = tail -> previous;
 	return *z;
 }

//insertAfter method
void List::insertAfter(int x, ListItr position){
	ListNode* node1 = new ListNode();
	ListNode * node3 = new ListNode();
	node1 -> value = x;

	node3 = position.current;

	node1-> next = node3 -> next;
	node1-> previous = node3;
	node3->next->previous = node1;
	node3->next = node1;
	
	

}

//insertBefore method
void List :: insertBefore(int x, ListItr position){
	ListNode * node2 = new ListNode();
	ListNode * node4 = new ListNode();

	node4 = position.current;

	node2 -> value = x;

	node2 -> next = node4;
	node2 -> previous = node4 ->previous;
	node4 ->previous -> next = node2;
	node4-> previous = node2;

	

}

//insertAtTail method
void List::insertAtTail(int x){
	ListNode* n = new ListNode();
	
	
	n->value = x;
	n->next = tail;
	n->previous = tail -> previous;
	tail->previous->next = n;
	tail-> previous = n;

	


}

//find Method
ListItr List :: find(int x){
	ListItr * p = new ListItr();

	p->current = head;

 	while (p->isPastEnd() == 0){
 		if (p->current->value != x){
 			p->current = p->current->next;
 		}

 		else{
 			return *p;
 		}
 		
 	}


 	return *p;

}

//Remove method
void List :: remove(int x){
	ListItr * q = new ListItr();
	*q = find(x);

	if (q->current != tail){
		q->current->previous->next = q->current->next;
		q->current->next->previous = q->current->previous;
		count = count-1;
		delete q;
	}

	//delete q;

}

//size method
int List :: size() const {

	int counter = 0;
	ListNode* n1 = head;

	while (n1-> next != tail){

		counter = counter +1;
		n1 = n1->next;
	}

	//delete n1;
return counter;

}

//printList method
void printList(List& source, bool forward){

	ListItr * i1 = new ListItr();


	if (forward == 1) {
		*i1 = source.first();
		while (i1->isPastEnd() == 0){
			if(source.isEmpty() == 1){
				cout << endl;
			}
			cout << i1->retrieve() << " ";
			i1->moveForward();
		}
		
	}

	else{
		*i1 = source.last();

		while (i1->isPastBeginning() == 0){
			if(source.isEmpty() == 1){
				cout << endl;
			}
			cout << i1->retrieve() << " ";
			i1->moveBackward();
		}

		
		
	}
	delete i1;
	cout << endl;

}






