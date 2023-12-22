//heapNode.h

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class heapNode {
public:
    heapNode();         // Constructor
    char value;          // The value of the node!
    int freq; 			// frequency of the character
    heapNode* left;
    heapNode* right;
    // List needs access to value, next, and previous
    friend class heap;
};

#endif