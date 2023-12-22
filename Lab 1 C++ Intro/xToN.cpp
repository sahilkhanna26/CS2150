//Sahil Khanna (sk5xvh)
//01.24.2022
//xToN.cpp

#include <iostream>
using namespace std;

int tmp = 1;

int xton(int a, int b){
  
  if (b == 0){
    return tmp;
  }
  else{
    tmp = tmp * a;
    b = b-1;
    return xton(a,b);
  }
}

int main () {
  int x, y, z;

  cin >> x;
  cin >> y;

  z = xton(x,y);

  cout<< z << endl;
    return 0;

}
