#include <iostream>
#include <memory>
using namespace std;

class B;
class A{
public:
	shared_ptr<B> pb_;
    // weak_ptr<B> pb_;
    ~A(){
        cout << "A delete\n";
    }
};
class B{
public:
    shared_ptr<A> pa_;
    ~B(){
        cout << "B delete\n";
    }
};

void fun(){
    shared_ptr<B> pb(new B());
    cout << "pb.use_count " << pb.use_count() << endl;//1
    shared_ptr<A> pa(new A());
    cout << "pa.use_count " << pa.use_count() << endl;//1

	//两个shared_ptr指针互相引用导致的资源释放失败
    pb->pa_ = pa;
    cout << "pb.use_count " << pb.use_count() << endl;//1
    cout << "pa.use_count " << pa.use_count() << endl;//2
    pa->pb_ = pb;
    cout << "pb.use_count " << pb.use_count() << endl;//2：由于share_ptr是共享资源，所以pb所指向的资源的引用计数也会加1
    cout << "pa.use_count " << pa.use_count() << endl;//2
}//程序结束时，没有调用A和B的析构函数

int main(){
    fun();
    system("pause");

	/*
	可以看到fun函数中pa ，pb之间互相引用，两个资源的引用计数为2，
	当要跳出函数时，智能指针pa，pb析构时两个资源引用计数会减一，
	但是两者引用计数还是为1，导致跳出函数时资源没有被释放（A B的析构函数没有被调用），
	如果把其中一个改为weak_ptr就可以了，我们把类A里面的shared_ptr<B> pb_; 
	改为weak_ptr<B> pb_;

	资源B的引用开始就只有1，当pb析构时，B的计数变为0，B得到释放，
	B释放的同时也会使A的计数减一，同时pa析构时使A的计数减一，
	那么A的计数为0，A得到释放。
	*/
	return 0;
}

// g++ weak_ptr.cpp -o weak_ptr