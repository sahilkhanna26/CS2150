/*
 * Filename: postfixCalculator.cpp
 * Description: postfixCalculator implementation
 * Author: Sahil Khanna
 * Date: 7th Feb 2022
 */ 


#include <iostream>
#include "Stack.h"
using namespace std;


#include "postfixCalculator.h"

//Constructor

postfixCalculator :: postfixCalculator(){

}

void postfixCalculator :: addition() {
    if (s.empty() == 0) {
        int x = s.top();
        s.pop();
        int y = s.top();
        s.pop();
        int result = x+y;
        s.push(result);
        
    }
    else{
        exit(-1);
    }
}


void postfixCalculator :: subtraction() {
    if (s.empty() == 0){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        int res = b-a;
        s.push(res);

    }

    else{
        exit(-1);
    }

}



Stack postfixCalculator :: getter() const{

    return s;
}


void postfixCalculator :: append(int x){
    s.push(x);
}

void postfixCalculator :: multiplication(){
    if (s.empty() == 0){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        int res = a*b;
        s.push(res);

    }

    else{
        exit(-1);
    }


}



void postfixCalculator :: division(){
    if (s.empty() == 0){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        int res = b/a;
        s.push(res);

    }

    else{
        exit(-1);
    }
}

void postfixCalculator :: negation(){
    if (s.empty() == 0){
        int a = s.top();
        int result = a * -1; 
        s.push(result);

    }

    else{
        exit(-1);
    }
}



