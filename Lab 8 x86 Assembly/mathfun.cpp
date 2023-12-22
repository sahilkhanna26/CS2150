// matb.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int  main () {

    // delcare the local variables
    long  n1, n2, result1, result2;

    // how big is the array we want to use?
    cout << "Enter Integer 1:  ";
    cin >> n1;
  

    cout << "Enter Integer 2:  ";
    cin >> n2; 
   

    // sum up the array and print out results
    result1 = product(n1, n2);
    cout << "Product: " << result1 << endl;
    result2 = power(n1, n2);
    cout << "Power: " << result2 << endl;

   

    // all done!
    return 0;
}