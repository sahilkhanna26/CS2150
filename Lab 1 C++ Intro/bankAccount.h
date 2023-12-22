//Sahil Khanna(sk5xvh); 01.27.2022; bankAccount.h


#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H 
#include <iostream>
using namespace std;



class bankAccount{
public:

    bankAccount();                    // default constructor
    bankAccount(double amount);           // constructor with name parameter
    ~bankAccount();			// destructor
	double withdraw(double amount);
	double deposit(double amount);
	double getBalance() const;
private:
	double balance;


};

#endif
