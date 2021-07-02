#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;


/*
//void assign (initializer_list<value_type> il);  //???????????????
int main()
{
	list<int> first;
	list<int> second;

	//void assign (size_type n, const value_type& val);
	first.assign(7, 100);                      // 7 ints with value 100
	for (auto e : first)
		cout << e << " ";
	cout << endl;



	//void assign (InputIterator first, InputIterator last);
	second.assign(first.begin(), first.end()); // a copy of first
	for (auto e : second)
		cout << e << " ";
	cout << endl;

	//assign(_Iter _First, _Iter _Last);
	int myints[] = { 1776,7,4 };
	first.assign(myints, myints + 3);
	for (auto e : first)
		cout << e << " ";
	cout << endl;

	return 0;
}
*/




/*
int main()
{
	list<int> L;
	cout << "L.empty:    " << L.empty() << endl;
	L.push_back(1);
	L.push_back(2);
	cout<<L.size()<<endl;
	L.assign(3, 0);

	for (auto e : L)
		cout << e<<" ";
	cout << endl;

	L.resize(5);
	cout << "L.max_size:"<< L.max_size() << endl;  //357913941
	cout << "L.size:    "<< L.size() << endl;
	return 0;
}
*/



int main()
{
//iterator begin();
//const_iterator begin() const;
	list<int> L;  //构造的list中包含n个值为val的元素
	L.push_back(1);
	L.push_back(2);

	list<int>::iterator it = L.begin();
	int arr[] = { 2, 3, 4, 5, 6, 7 };
	const list<int> L2(arr, arr+6);

	//L2.pop_back(5);  //const 限制的常链表不能修改
	//it = L2.end();  //const 限制的常链表不能用普通迭代器迭代

	//const或非const的迭代器不能指向const 限制的常链表
	//const list<int>::iterator conit = L2.end();  //error:-->
	const list<int>::const_iterator conit = L2.end();  //true
//不存在用户定义的从
//"std:List const iterator<std:：List val<std:conditional t<true，std:：List simple types <int>
//，std:List iter types<int，size t，ptrdiff t，int*，const int*，int&，const int&，std:List node<int，void*>*>>>>"到
//"std:List iterator<std:List val<std:conditional t<true，std:：List simple types <int>
//，std:List iter types<int，size t，ptrdiff t，int*，const int*，int&，const int&，std:List node <int，void*>*>>>>"的适当转换

	const list<int>::iterator conit = L.end();
	list<int>::iterator it1 = L.end();
	*conit = 2;
	//*conit++;  //const的迭代器不能++（迭代器迭代的对象不能改变）
	*it1 = 2;
	*it1++;
	return 0;
}






//  explicit list(size_type n, const T& v = T(), const A& al = A());  //???????

/*
int main()
{
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> mylist(ar, ar + 10);  //用数组元素的地址做为参数创建链表
	list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = mylist.rbegin();
	while (rit != mylist.rend())
	{
		cout << *rit << " ";
		++rit; // --
	}
	cout << endl;
	return 0;
}
*/


/*
int main()
{
	//list (size_type n, const value_type& val = value_type()) ;
	list<int> L;  //构造的list中包含n个值为val的元素
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	L.push_back(6);
	L.push_back(7);
	L.push_back(8);

	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;




	//list(const list& x);
	list<int> L2(L);  //调用拷贝构造函数以对象构造对象
	it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;





	list<int>::iterator F = L.begin();
	list<int>::iterator T = F;
	int i = 3;
	while(i--)
		T++;
	//list(const_iterator first, const_iterator last,const A& al = A());
	list<int> L3(F, T);  //用迭代器 [first, tail) 区间中的元素构造list


	list<int>::iterator It = L3.begin();
	while (It != L3.end())
	{
		cout << *It << " ";
		++It;
	}
	cout << endl;
}
*/







/*
int main()
{
	//list (size_type n, const value_type& val = value_type()) ;
	list<int> L(10, 6);  //构造的list中包含n个值为val的元素

	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
*/


/*
int main()
{
	//list();
	list<int> L;  //构造空的链表

	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
*/