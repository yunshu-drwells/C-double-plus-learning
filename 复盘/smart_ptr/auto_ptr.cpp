#include "Test.h"
#include <memory>
#include <vector>

int main(){
    auto_ptr<Test> ptest(new Test("0"));
    ptest->setStr("hello ");
    ptest->print();
    ptest.get()->print();
    ptest->getStr() += "world !";
    (*ptest).print();
    ptest.reset(new Test("666"));
    ptest->print();
	cout<<"---------------------"<<endl<<endl;
	/*
	智能指针可以像类的原始指针一样访问类的public成员，成员函数get()返回一个原始的指针，
	成员函数reset()重新绑定指向的对象，而原来的对象则会被释放。
	*/



	//1.两个auto_prt指针不能指向同一个内存
	// Test* t = new Test("567");
	// auto_ptr<Test> ptest1(t);
	// auto_ptr<Test> ptest2(t);


	//2.不要将auto_prt对象作为STL容器的元素，C++标准明确禁止这样做
	vector<auto_ptr<Test>> v(10); //程序可以执行，但是不能使用容器中的auto_ptr智能指针赋值
	/*
	当我们对智能指针进行赋值时，如ptest2 = ptest，ptest2会接管ptest原来的内存管理权，
	ptest会变为空指针，如果ptest2原来不为空，则它会释放原来的资源，基于这个原因，
	应该避免把auto_ptr放到容器中，因为算法对容器操作时，很难避免STL内部对容器实现了赋值传递操作，
	这样会使容器中很多元素被置为NULL。
	*/
	auto_ptr<Test> ptest3(new Test("3"));
    auto_ptr<Test> ptest4(new Test("4"));
    ptest3 = ptest4;
    ptest3->print();
    if(ptest4.get() == NULL)cout<<"ptest4 = NULL\n";
	cout<<"---------------------"<<endl<<endl;



	/*
	还有一个值得我们注意的成员函数是release，这个函数只是把智能指针赋值为空，
	但是它原来指向的内存并没有被释放，相当于它只是释放了对资源的所有权，析构函数没有被调用。
	*/
	auto_ptr<Test> ptest5(new Test("5"));
    ptest5.release(); //并没有调用析构函数
	//想要在中途释放资源，而不是等到智能指针被析构时才释放，我们可以使用ptest.reset(); 
	ptest5.reset();
	cout<<"---------------------"<<endl<<endl;



	//3.不能将数组作为auto_ptr的参数
	Test* t_arr = new Test[10];
	auto_ptr<Test> ptest6(t_arr); //出错
	/*
	munmap_chunk(): invalid pointer
	Aborted (core dumped)
	*/

    return 0;
}
// g++ auto_ptr.cpp -o auto_ptr

/*
auto_ptr局限性
1.两个auto_prt指针不能指向同一个内存：
会析构两次，其时只有一个对象t，程序很可能会崩溃

2.不要将auto_prt对象作为STL容器的元素，C++标准明确禁止这样做。

3.不能将数组作为auto_ptr的参数
*/