//Sahil Khanna(sk5xvh); 01.27.2022; bankAccount.cpp

#include <iostream>

using namespace std;

#include "bankAccount.h"

//Constructors and Destructors
bankAccount::bankAccount(){
	balance = 0.00;
}

bankAccount::bankAccount(double amount){
	balance = balance + amount;
}

bankAccount::~bankAccount(){

}

//withdraw method
double bankAccount:: withdraw(double amount){
	


	if (balance < amount) {
		return balance;
	}
	else{
		balance = balance - amount;
		return balance;
	}
	
}


//deposit method

double bankAccount:: deposit(double amount){
	balance = balance + amount;

	return balance;
}

//getbalance method

double bankAccount::getBalance() const{
	return balance;
}

