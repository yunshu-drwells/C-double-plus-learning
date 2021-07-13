#include "Test.h"
#include <memory>

int main(){
    shared_ptr<Test> ptest1(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    shared_ptr<Test> ptest3(new Test("789"));

	cout<<"ptest1:"<<ptest1.use_count()<<endl;
    cout<<"ptest2:"<<ptest2.use_count()<<endl;
    cout<<"ptest3:"<<ptest3.use_count()<<endl;
    ptest3 = ptest2;//"456"引用次数加1，“789”引用次数减1
	cout<<"ptest1:"<<ptest1.use_count()<<endl;
    cout<<"ptest2:"<<ptest2.use_count()<<endl;
    cout<<"ptest3:"<<ptest3.use_count()<<endl;

    ptest1.reset(); //此时“123”销毁
    ptest2.reset();
    cout<<"done !\n";
    return 0;
}
// g++ shared_ptr.cpp -o shared_ptr