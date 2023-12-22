// Sahil Khanna (sk5xvh) ListItr.cpp
#include <iostream>
#include <string>
using namespace std;

#include "ListItr.h" 
#include "List.h"
#include "ListNode.h"

//Constructor
ListItr :: ListItr(){
	//current = new ListNode();
	current = NULL;
}

//Constructor 2
ListItr :: ListItr(ListNode* theNode){
	theNode = new ListNode();

}



//isPastEnd Method
bool ListItr :: isPastEnd() const{
	if (current->next == NULL){
		return 1;

	}
	return 0;
}

//isPastBeginning Method
bool ListItr :: isPastBeginning() const{

	if (current-> previous == NULL){
		return 1;
	}
	return 0;
}

//moveforward
void ListItr :: moveForward(){
	if (isPastEnd() == 0){
		current = current->next;
	}

}

//movebackward
void ListItr :: moveBackward(){
	if (isPastBeginning() == 0){
		current = current->previous;
	}
	}


//retrieve
int ListItr :: retrieve() const {
	int x = 0;
	x = current->value;
	return x;
}