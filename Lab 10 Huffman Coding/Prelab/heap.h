// heap.h 
//CS 2150 lab 10 
//From the code provided 

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "heapNode.h"

using namespace std;

class heap {
public:
    heap();
    heap(vector<heapNode*> vec);
    ~heap();

    void insert(heapNode* x);
    heapNode* findMin();
    heapNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<heapNode*> the_heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif