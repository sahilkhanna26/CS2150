
#include <iostream>
using namespace std;
#include <climits> /* see definition */
#include <math.h>


void sizeOfTest(){
	cout << "Size of int: " << sizeof(int) << endl; 
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float)<< endl;
	cout << "Size of double: " << sizeof(double)<< endl;
	cout << "Size of char: " << sizeof(char)<< endl;
	cout << "Size of bool: " << sizeof(bool)<< endl;
	cout << "Size of int*: " << sizeof(int*)<< endl;
	cout << "Size of char*: " << sizeof(char*)<< endl;
	cout << "Size of double*: " << sizeof(double*)<< endl;
}


void overflow(){
	unsigned int i = UINT_MAX;
	unsigned int i1 = i + 1;

	cout<< "4294967295 + 1 = " << i1 << endl;

}


void outputBinary(unsigned int x){

	string result = "";
	int counter = 1; 
	unsigned int m = x;


	for (int i=40; i>0; i--) {



			if (counter%5 ==0 && pow(2,i)>x){
				result = " " + result;
			}

			else{
				if( x%2 == 0){
					result = "0" + result  ;
				}
				else{
					result = "1" + result ;
				}
				x = x/2;
			}
		counter ++ ;


}
	cout<<result<<endl;

}


int main(){
	unsigned int x;
	cin >> x;
	sizeOfTest();
	overflow();
	outputBinary(x);

}





