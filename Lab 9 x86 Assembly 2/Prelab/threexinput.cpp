#include <iostream>
#include <cstring>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);

int main(){
	timer t;
	int x;

	cout<< "Enter a number: ";
	cin >> x; 

	int n; 

	cout << "Enter iterations of subroutine: ";
	cin >> n;

	int result1 = threexplusone(x);

	t.start();

	for (int i = n; i>0; i--){
		threexplusone(x);
	}

	t.stop();


	cout<< "Steps: "<< result1<<endl;


	return 0;

}