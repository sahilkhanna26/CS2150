//puzzleNode.h

#ifndef PUZZLENODE_H
#define PUZZLENODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class puzzleNode {
public:
    puzzleNode();// Constructor
    string value;
    int dist;
   


};

#endif