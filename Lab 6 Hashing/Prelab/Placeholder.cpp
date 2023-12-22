#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "timer.h"
using namespace std;


#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
string word;



bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main (int argc, char **argv){

    string directions[8] = {"N","NE","E","SE","S","SW","W","NW"};
	timer t;
    t.start();


	string line;

	int rows;
	int cols;
	

	

	string dictfile(argv[1]);
	string gridfile(argv[2]);



	

	int c = 0;
	ifstream file(dictfile);

	while(getline(file,line)){
		c= c+1;
	}
	file.close();

	hashTable h1;
	h1.setSize(2*c);

	ifstream file1(dictfile);




	if (file1.is_open()){
	 	while(getline(file1,line)){
	 		
	 		
	 		h1.insert(line);


	 	}

	 		
	 }

	else{
	 	cout<< "error in file opening";
	 	return 1;

	 }
	 file1.close();

	readInGrid(gridfile,rows,cols);

	 

string k;
int counter;


for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
    		for (int i = 0; i < 8; i++) {




    			// if (i == 0){
    			// 	k = "N";
    			// } 

    			// else if(i == 1) {
    			// 	k = "NE";
    			// }
    			// else if(i == 2) {
    			// 	k = "E";
    			// }

    			// else if(i == 3) {
    			// 	k = "SE";
    			// }

    			// else if(i == 4) {
    			// 	k = "S";
    			// }

    			// else if(i == 5) {
    			// 	k = "SW";
    			// }

    			// else if(i == 6) {
    			// 	k = "W";
    			// }

    			// else if(i == 7) {
    			// 	k = "NW";
    			// }

                k= directions[i];





    			for (int l=3; l<23; l++){




    			word  = getWordInGrid(r, c, i, l, rows, cols);

    			if (word != getWordInGrid(r, c, i, l-1, rows, cols)){


    				
    				if (h1.find(word) == true){
    					counter = counter +1;
    	
    				cout<< k << " (" << r << ", " << c << "):       " << word<<endl;

    		}

    	}
    			
    	}
    }
}
}
	
	cout<< counter<< " words found" << endl;
	t.stop();
	int time =t.getTime() *1000;
    cout << time << endl;

    return 0;
}


bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
           // cout << grid[r][c];
        }
       // cout << endl;
    }
    return true;
}


string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;

}