#include <iostream>
#include <math.h>
#include <stack>
#include <string>

using namespace std;

int counter;



int numberOfBits(int n){


	if (n == 0){
		return counter;


	}

	else if (n%2 == 0){

		return numberOfBits(n/2);
	}

	else {
		counter = counter + 1;
		return numberOfBits(n/2);


	}

}





string converter(string s, int base1, int base2){

	int i = 0;
	int power = s.length() - 1;
	string result = "";
	stack <int> attack;
	int base10= 0;




	for(int k=0; k<s.length(); k ++){

		if(s[k]== '0'| s[k]== '1' | s[k]== '2' | s[k]== '3'| s[k]== '4'| s[k]== '5'| s[k]== '6'| s[k]== '7'| s[k]== '8'| s[k]== '9'){
			char c = s[k];
			base10 = c - 48; 
		}

		else{
			char c = s[k];
			base10 = c - 55;
		}

		i = i  +  (base10* pow(base1, power));

		power --;  

	}

	int remainder = 0;

	while ( i > 0 ){
		remainder = i%base2; 

		attack.push(remainder);



		i = i/base2;
	}


	while(attack.empty() != 1){
		int s = attack.top();
		attack.pop();

		char ch = (char) s;


		if( s>=0 && s<= 9){
			ch = ch + '0';
			result = result.append(string(1,ch));
		}

		else{
			ch = ch +'7';
			
			result = result.append(string(1,ch));
		}

	}
	return result;


}


int main (int argc, char **argv){
	string s1(argv[1]);
	string s2(argv[2]);
	string s3(argv[3]);
	string s4(argv[4]);


	cout<< s1 << " has "<< numberOfBits(stoi(s1)) << " bit(s)"<< endl;

	cout<< s2 << " (base " << s3 << ") " << " = " << converter(s2, stoi(s3), stoi(s4)) << " (base " << s4 << ")" << endl; 



}




