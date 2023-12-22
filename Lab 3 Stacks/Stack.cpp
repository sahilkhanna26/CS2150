/*
 * Filename: Stack.cpp
 * Description: Stack class implementation
 *
 * Date: 9th Feb 2022.
 Sahil Khanna (sk5xvh) Stack.cpp

*/



#include <iostream>
#include <string>
using namespace std;


#include "Stack.h"
#include "stacknode.h"

// Default Constructor

Stack :: Stack(){
    count = 0;
    head = new stacknode();
    tail = new stacknode();

    head->next= tail;

}

Stack :: ~Stack(){
    while (size() != 0){
        head-> next = tail;
        count = 0;
             
    }
    delete head;
    delete tail;
}

int Stack :: size(){
    int counter = 0;
    stacknode* n1 = head; 

    while (n1-> next != tail){

        counter = counter +1;
        n1 = n1->next;
    }

    return counter;
}

bool Stack :: empty(){
    if (size() == 0){
        return 1;
    }
    return 0; 
}


void Stack :: push(int e){
    stacknode* n2 = new stacknode();
    n2 -> value = e;

    n2->next = head-> next;
    head-> next= n2;

    
}

void Stack :: pop(){
    head -> next = head->next->next;
    count = count -1; 
}

int Stack :: top(){
    return head->next->value;

}