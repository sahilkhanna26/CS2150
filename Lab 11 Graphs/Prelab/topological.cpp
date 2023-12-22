//This file has parts of it from fileio2.cpp
//Topological.cpp

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

// we want to use parameters

/**
 * @brief This program performs a topological sort on inputs
 * @param a no parameters
 * @return A valid topological sort of the vertices
 * @author Sahil Khanna (sk5xvh)
 * @file Topological.cpp 
 * 
 */
int main(int argc, char** argv) {

    unordered_map<string, int>  index;
    int counter = 0;


    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    int matrix[100][100];



    // read in two strings
    string s1, s2;

    while(s1!= "0" && s2!="0"){
        file >> s1;
        file >> s2;
        if(s1!= "0" && s2!= "0"){
            if(index.find(s1) == index.end()){
                index[s1] = counter;
                counter++;
            }

            if (index.find(s2) == index.end()){
                index[s2] = counter;
                counter++;
            }

            int r = index[s1];
            int c = index[s2];


            matrix[r][c]=1;

            


          // cout << s1 << " " <<s2<< endl;
          // cout<< r << "x" << c << endl;

          
        }
       

    }

   




    int no_of_verteces = index.size();
    int indegrees[no_of_verteces];
    unordered_map<int,string> verteces;
    int g = 0;

    for (auto itr = index.begin(); itr != index.end(); itr++){ 
         string s = itr->first;
         int place = itr->second;
         verteces[place]=s;
        //cout<< verteces[g];
        g++;
    }



    for (int col = 0; col<no_of_verteces; col++){
        int column_sum = 0;

        for(int row = 0 ; row<=no_of_verteces; row++){
            column_sum =column_sum + matrix[row][col];
            indegrees[col] = column_sum;
            
        }
        //cout<< indegrees[col];
    }

    queue<int> q;
    int first_index =0;

    for(int n=0; n<no_of_verteces; n++){
        if (indegrees[n]==0){
            first_index=n;
            q.push(n);

        }

    }

        while(q.empty() == false){
            int x = q.front();
            q.pop();
            cout<< verteces[x]<< " ";
            // cout<< verteces[x];
            // cout<< indegrees[x];

            for(int column = 0; column < no_of_verteces; column++){
                if(matrix[x][column]==1){
                    indegrees[column]= indegrees[column]-1;
                
                    if(indegrees[column]==0){
                        q.push(column);
                    
                
            }
        }
    }

    }

    cout<< endl;




 
    
    // output those strings
  

    // close the file before exiting
    file.close();
}