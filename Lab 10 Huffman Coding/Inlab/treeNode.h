//treeNode.h

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class treeNode {
public:
    treeNode();// Constructor
    char value;// The value of the node 		
    treeNode* left;
    treeNode* right;


};

#endif