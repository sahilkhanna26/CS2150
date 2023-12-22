/*
 * Filename: stacknode.h
 * Description: stacknode class definition
 *
 * Date: 9th Feb 2022.
 Sahil Khanna (sk5xvh) stacknode.h

*/

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std; 


class stacknode{

public: 
    //constructor
    stacknode();


private: 
    int value; 
    stacknode* next; 


    friend class Stack; 

};


#endif