#include <iostream>
#include <string>
using namespace std;
class Test{
public:
	Test()=default;
    Test(string s){
    	str = s;
    	cout<<"Test("<<s<< ")creat\n";
    }
    ~Test(){
        cout<<"Test delete:"<<str<<endl;
    }
    string& getStr(){
        return str;
    }
    void setStr(string s){
        str = s;
    }
    void print(){
        cout<<str<<endl;
    }
private:
    string str;
};