// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// Decoding: parts of this code are from inlab-skeleton.cpp 

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include "treeNode.h"
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

treeNode* root = new treeNode();
unordered_set<string> v;


void treeBuilder(treeNode* root, string str, char data){

    if(str.size() ==0){
        root->value=data;
    }

    if(str[0]=='0'&& str.size()>0){        //We go left
        if(root->left == NULL){
            treeNode* dummyNode = new treeNode();
            root->left = dummyNode;
            dummyNode->value = '\0';
            treeBuilder(root->left, str.substr(1, str.length()),data);
    }
    else{
        treeBuilder(root->left, str.substr(1, str.length()),data);

    }

    }

    else if (str[0] == '1'&& str.size()>0){
        if(root->right == NULL){
            treeNode* dummyNode = new treeNode();
            root->right = dummyNode;
            dummyNode->value = '\0';
            treeBuilder(root->right, str.substr(1, str.length()),data);
    }

    else {
        treeBuilder(root->right, str.substr(1, str.length()),data);

    }
    }

}


void treeDestructor(treeNode* root){
    if (root->left == NULL && root->right == NULL){
        delete root;
    }

    else if(root->left == NULL && root->right != NULL){
        
        treeDestructor(root->right);
    }
    else if(root->right == NULL && root->left != NULL){
        
        treeDestructor(root->left);
    }

    else{
        treeDestructor(root->right);
        treeDestructor(root->left);
    }



}





// main(): we want to use parameters
int main (int argc, char** argv) {

    root->value = '\0';
    root->left = NULL;
    root->right= NULL;

    map<string,string> m;


    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;

        m.insert(pair <string, string> (prefix,character)); 
    

    }




    

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

   unordered_set<string> v; 

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;

   
  
    for (auto itr = m.begin(); itr != m.end(); itr++){
        string s2 = itr->first;
        v.insert(s2);
    }


    for (auto itr = m.begin(); itr != m.end(); itr++){
        string s = itr->first;
        string s1 = itr->second;
        char c = s1[0];
        

        treeBuilder(root, s, c);
    }

    // cout<< root->right->right->value;


    treeNode* root2 = root;

    string encoded = allbits;

    while(encoded.size()>0){
        char target = encoded[0];

        if(root2->value != '\0'){
            cout<< root2->value;
            root2= root;
        }
        if(target == '0'){
            root2 = root2->left;
        }
        else{
            root2 = root2->right;
        }
        encoded = encoded.substr(1);
        // cout<< encoded<<endl;
    }

    //char target2 = encoded[0];

        if(root2->value != '\0'){
            cout<< root2->value<<endl;
            root2= root;
        }
        // if(target2 == '0'){
        //     root2 = root2->left;
        //     cout<< root2->value<<endl;
        // }
        // else{
        //     root2 = root2->right;
        //     cout<< root2->value<<endl;
        // }
        



   

        treeDestructor(root);
        delete root2;

    // close the file before exiting
    file.close();

    return 0;
}
