#include <iostream>   
using namespace std;   
class Overloading{   
      int n;   
   public:   
       Overloading():n(8){}   
       void operator ++(){n = n+4;}   
       void Print() {cout<<"The Count is: "<<n;}   
};   
int main(){   
    Overloading o;   
    ++o;// calling of a function "void operator ++()"   
    o.Print();
    return 0;
}

