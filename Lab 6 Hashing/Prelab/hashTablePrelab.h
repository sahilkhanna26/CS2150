


// Sahil Khanna; 17.03.2022; Lab 6
// hashTable.h: Hash Table Definition
// CS 2150: Lab 6



#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <array>

using namespace std;

class hashTable{

public:
	hashTable();
	~hashTable();



	void insert(string s);
	unsigned int hFunction(string s);
	bool find(const string s);
	void setSize(int i);


private:

	
	vector<string>* htable;

};

#endif