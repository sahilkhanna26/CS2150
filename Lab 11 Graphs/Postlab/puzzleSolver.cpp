#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <array>
#include <queue>
using namespace std;
/**
 * @brief This program performs a 8 puzzle solve
 * @param the grid
 * @return No.of steps taken to get the search
 * @author Sahil Khanna (sk5xvh)
 * @file puzzleSolver.cpp 
 * 
 */
string input;
string target = "123456780";
int no_of_steps = 0;
int counter =0;
unordered_map<string, int> permutation_map;
bool invalidChecker(string string1){
	int inv_counter= 0;

	for (int l=0; l<string1.length()-1; l++){
		char ch = string1[l];
		for (int k = l+1; k<string1.length(); k++){
			char next_char = string1[k];
			if (ch>next_char){
				if(ch != '0' && next_char != '0'){
				inv_counter++;
			}
			}
		}
	}
	
	if (inv_counter%2 == 1){
		return false;
	}
	return true;
	
}
vector<string> generateNeighbor(string str){
	
	vector <string> neighbors;
	if (str.find("0")==0){
		string s1 = str;
		swap(s1[0],s1[1]);

		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}

		

		string s2 = str;
		swap(s2[0],s2[3]);


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}

	}

	else if (str.find("0") == 1){
		string s1 = str;
		string s2 = str;
		string s3 = str;

		swap(s1[1],s1[0]);
		swap(s2[1],s2[2]);
		swap(s3[1],s3[4]);


		
		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}

		if(invalidChecker(s3) == true){
			neighbors.push_back(s3);
		}







	}
	else if (str.find("0") == 2){
		string s1 = str;
		string s2 = str;

		swap(s1[2], s1[1]);
		swap(s2[2], s2[5]);


		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}


	}
	else if (str.find("0") == 3){

		string s1 = str;
		string s2 = str;
		string s3 = str;

		swap(s1[3],s1[0]);
		swap(s2[3],s2[4]);
		swap(s3[3],s3[6]);


		
		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}

		if(invalidChecker(s3) == true){
			neighbors.push_back(s3);
		}


		
	}
	else if (str.find("0") == 4){
		string s1 = str;
		string s2 = str;
		string s3 = str;
		string s4 = str;

		swap(s1[4],s1[1]);
		swap(s2[4],s2[3]);
		swap(s3[4],s3[5]);
		swap(s4[4],s3[7]);

		
		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}

		if(invalidChecker(s3) == true){
			neighbors.push_back(s3);
		}

		if(invalidChecker(s4) == true){
			neighbors.push_back(s4);
		}


	}
	else if (str.find("0") == 5){
		
		string s1 = str;
		string s2 = str;
		string s3 = str;

		swap(s1[5],s1[2]);
		swap(s2[5],s2[4]);
		swap(s3[5],s3[8]);


		
		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}

		if(invalidChecker(s3) == true){
			neighbors.push_back(s3);
		}


	}
	else if (str.find("0") == 6){
		string s1 = str;
		string s2 = str;

		swap(s1[6], s1[3]);
		swap(s2[6], s2[7]);


		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}
	}
	else if (str.find("0") == 7){
		
		string s1 = str;
		string s2 = str;
		string s3 = str;

		swap(s1[7],s1[6]);
		swap(s2[7],s2[4]);
		swap(s3[7],s3[8]);


		
		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}

		if(invalidChecker(s3) == true){
			neighbors.push_back(s3);
		}

	}
	else if (str.find("0") == 8){

		string s1 = str;
		string s2 = str;

		swap(s1[8], s1[5]);
		swap(s2[8], s2[7]);


		if(invalidChecker(s1) == true){
			neighbors.push_back(s1);
		}


		if(invalidChecker(s2) == true){
			neighbors.push_back(s2);
		}
	}

	//counter++;
	return neighbors;
}




int main(){
	string line1;
	int x = 3;
	while (x!=0){
		string s;
		getline(cin,s);
		line1=line1 + s;
		//cout<< line1;
		x--;
	}

	//cout<< line1;

	for(int k=0; k<line1.length(); k++){
		char c = line1[k];
		if (c != ' '){
			input = input + c; 
		}
	}
	//cout<< input;
	
	cout<< "SOLVING PUZZLE"<<endl;
	if (invalidChecker(input) == false){
		cout<< "IMPOSSIBLE"<< endl;
		exit(0);
	}



	
	permutation_map[input]=0;
	no_of_steps = 1;
  

	queue<string> q1;
	q1.push(input);
	
	vector<string> v1;

	while(permutation_map.find(target)==permutation_map.end()){
		counter = 0;
		string s = q1.front();
		if(invalidChecker(s)==true){
		q1.pop();

		vector<string> v = generateNeighbor(s);
		counter++;
		int size = v.size();
		for(int i=0; i<size; i++){
			string currString = v.back();
			//cout<< currString<< endl;
			v.pop_back();
			if(permutation_map.find(currString)==permutation_map.end()){
				
					v1.push_back(currString);
				q1.push(currString);
				permutation_map[s]=no_of_steps;
			
		}
		}
	}
	no_of_steps = no_of_steps + counter;
	

	}
	int result =0;
	result = no_of_steps;
	cout<< result;     

	return 0;
}