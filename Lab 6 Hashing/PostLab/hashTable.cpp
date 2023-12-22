

#include <iostream>
#include <list>
#include "hashTable.h"
#include <math.h>
#include <vector>

using namespace std;


//Constructor
hashTable :: hashTable(){
	size = 100000;
	hTable = NULL;
	hTable = new vector<string>[size];
}


//Destructor
hashTable :: ~hashTable(){
	delete[] hTable;

}

void hashTable :: insert(string s){
	unsigned int i = hFunction(s);

	// while(hTable[i].empty() == false){
	// 	// if (i<size){
	// 	// 	i = i+1;
	// 	// }
	// 	// else{
	// 	// 	i = i%10;
	// 	// }
	// }
	hTable[i].push_back(s);
	
}


unsigned int hashTable :: hFunction(string s){

	unsigned int result;

	result = 0;

	for (int k = 0; k<s.length(); k++){

	result = result + s[k];

}

	result = result % size;

	return result; 

}


bool hashTable :: find(string s){
	unsigned int n = 0;
	n = hFunction(s);

	for (int i = 0; i<hTable[n].size(); i++){
		if (hTable[n][i] == s){
			return true;
		}
	}

	return false;
}

void hashTable:: setSize(int i){
	size = i;
}







