
#include <iostream>
#include <array>
#include "hashTable.h"
#include <math.h>

using namespace std;


//Constructor
hashTable :: hashTable(){
	size = 100000;
	hTable = NULL;
	hTable = new string[size];
	

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
	while(hTable[i].empty() == false){
	if(i<size){
		i = i+1;
	}
	else{
		i = i%10;
	}
}
	hTable[i]= s;





	

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
	for (int i = 0; i<size; i++ ){
		if (hTable[i]==s){
			return true;
		}
	}



	return false;
}





void hashTable :: setSize(int i){
	size = i;

}










