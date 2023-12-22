//heap.cpp
//From the code provided for CS 2150 Lab10
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "heapNode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    the_heap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<heapNode*> vec) : heap_size(vec.size()) {
    the_heap = vec;
    the_heap.push_back(the_heap[0]);
    the_heap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(heapNode* x) {
    // a vector push_back will resize as necessary
    the_heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    heapNode* x = the_heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < the_heap[hole/2]->freq); hole /= 2) {
        the_heap[hole] = the_heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    the_heap[hole] = x; 
}

heapNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    heapNode* ret = the_heap[1];
    // move the last inserted position into the root
    the_heap[1] = the_heap[heap_size--];
    // make sure the vector knows that there is one less element
    the_heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    heapNode* x = the_heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (the_heap[child+1]->freq < the_heap[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > the_heap[child]->freq) {
            the_heap[hole] = the_heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    the_heap[hole] = x;
}

heapNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return the_heap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    the_heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

// void heap::print() {
//     cout << "(" << the_heap[0] << ") ";
//     for (int i = 1; i <= heap_size; i++) {
//         cout << the_heap[i] << " ";
//         // next line from http://tinyurl.com/mf9tbgm
//         bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
//         if (isPow2) {
//             cout << endl << "\t";
//         }
//     }
//     cout << endl;
// }