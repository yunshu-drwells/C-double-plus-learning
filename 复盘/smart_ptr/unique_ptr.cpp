#include "Test.h"
#include <memory>

unique_ptr<Test> fun(){
    return unique_ptr<Test>(new Test("789"));
}
unique_ptr<Test> foo(unique_ptr<Test> up){
    return up;
}
int main(){
    unique_ptr<Test> ptest(new Test("123"));
    unique_ptr<Test> ptest2(new Test("456"));
    ptest2 = std::move(ptest); //不能直接ptest2 = ptest,利用左值赋值就是拷贝赋值了
    if(ptest == NULL)cout<<"ptest = NULL\n";
    Test* p = ptest2.release(); //将智能指针ptest2赋空,返回值是智能指针维护的对象的指针
    p->print();
    ptest.reset(p); //Test("123")重新设置给ptest
    ptest->print();
    ptest2 = fun(); //这里可以用=，因为使用了移动构造函数
    ptest2->print();

    ptest = foo(move(ptest));
    ptest->print();
    return 0;
}
// g++ unique_ptr.cpp -o unique_ptr