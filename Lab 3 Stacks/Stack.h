/*
 * Filename: Stack.h
 * Description: Stack class definition
 *
 * Date: 8th Feb 2022.
 Sahil Khanna (sk5xvh) Stack.h

*/

#ifndef STACK_H
#define STACK_H


#include <iostream>
#include"stacknode.h"
using namespace std;



class Stack {
public:


// default constructor
    Stack();

// destructor
    ~Stack();

// empty method
    bool empty();

// push method
    void push(int e);

// pop method
    void pop();

// top method
    int top();

// size method
    int size();


private:
    stacknode* head;

    stacknode* tail;

    int count;

};

#endif