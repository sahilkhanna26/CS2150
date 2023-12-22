/*
 * Filename: postfixCalculator.h
 * Description: postfixCalculator definition
 * Author: Sahil Khanna
 * Date: 7th Feb 2022
 */ 

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream> 

#include "Stack.h"

using namespace std;


 
class postfixCalculator {

public:

	postfixCalculator();

	~postfixCalculator();

	void addition();

	void subtraction();

	Stack getter() const;

	void append(int x);

	void multiplication();

	void division();

	void negation();



private:

	Stack s;

};

#endif