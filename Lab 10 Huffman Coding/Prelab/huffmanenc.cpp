//
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include "heap.h"
#include "heapNode.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
unordered_map<char,string> output_map;

void treeTraverser(heapNode* root, string str){
    if((root->left == NULL) && (root->right == NULL)){
        output_map[root->value] = str;
        //cout<< root->value << str<< " ";
        }
    

    else{

       
        treeTraverser(root ->left, str+"0");
        treeTraverser(root->right, str+"1");
       


}
}


// we want to use parameters
int main(int argc, char** argv) {
    unordered_map<char,int> map;
    heap h;
    vector<char> v;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    int counter = 0;
    while (file.get(g)) {
        
        if((' ' <= g)&& (g<= '~')){
            v.push_back(g);
            counter++;
        }
    }



    for (int k=0;k<v.size();k++){
        char c = v[k];
        map[c]++;
    }
    // for (auto iter = map.begin(); iter != map.end(); iter++){
    //     cout<<" "<<  iter->first  << iter->second <<endl ;

    // }
    
    for (auto itr = map.begin(); itr != map.end(); itr++){ // Create Heap]
        heapNode* node = new heapNode();
        node->value = itr->first;
        node->freq = itr->second;
        node->left = NULL;
        node->right  = NULL;
        h.insert(node);
    }


    while(h.size()>1){
        heapNode* parent = new heapNode();
        parent->value = '\0';
        parent->left = h.deleteMin();
        parent->right = h.deleteMin();
        cout<<parent->left->value<<endl;
        cout<< parent->right->value<<endl;
        parent->freq = parent->right->freq + parent->left->freq;
        h.insert(parent);
    }


    
    heapNode* root= new heapNode();
    string s = "";
    root = h.findMin();
    //cout<<root->right->left->value<<endl;
    //cout<< root->right->right->value<<endl;
    treeTraverser(root,s);



    for (auto iter = output_map.begin(); iter != output_map.end(); iter++){
        cout<<  iter->first <<" " << iter->second<< endl ;

    }
    




    // a nice pretty separator
   cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen

    int distinct_symbols  = output_map.size();
   
    float initial_bits = counter * 8;

    

    string s5;

    while (file.get(g)) {
        if((' ' <= g)&& (g<= '~')){

        s5 = s5 + output_map[g];
        string s  = output_map[g];
        cout<< s << " ";
    }

    }
    float distinct_bits = s5.size();

   cout <<endl<< "----------------------------------------" << endl;


   //cost of huffman tree
   for(int p=0; p<map.size(); p++){

   }
   float cost = distinct_bits/counter;

   cout<< "There are a total of "<<counter<<" symbols that are encoded."<<endl;
   cout<< "There are "<<distinct_symbols<<" distinct symbols used."<<endl;
   cout<< "There were "<<initial_bits<<" bits in the original file."<< endl;
   cout<<"There were " <<distinct_bits<< " bits in the compressed file."<<endl;
   float compression_ratio = initial_bits/distinct_bits;
   cout<< "This gives a compression ratio of "<<compression_ratio<<"." <<endl;
   cout<<"The cost of the Huffman tree is "<< cost<<" bits per character."<<endl;


    // close the file
    file.close();




    return 0;
}