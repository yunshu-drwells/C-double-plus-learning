/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> first;
	list<int> second;


	first.assign(7, 100);                      // 7 ints with value 100
	for (auto e : first)
		cout << e << " ";
	cout << endl;


	second.assign(first.begin(), first.end()); // a copy of first
	for (auto e : second)
		cout << e << " ";
	cout << endl;


	int myints[] = { 1776, 7, 4 };
	first.assign(myints, myints + 3);
	for (auto e : first)
		cout << e << " ";
	cout << endl;


	//void assign(initializer_list<value_type> il);
	return 0;
}
*/





#include<iostream>
#include<string>
using namespace std;

//fjaljflakjaljflafajlfa

/*
void main()
{
string s;
//cin>>s;  //' '  \n
getline(cin, s);  //  \n  jfla falfjla
cout<<s<<endl;
}
*/




/*
void main()
{
string s("HelxoBit.");
//string tmp = s.substr();
//string tmp = s.substr(3);
string tmp = s.substr(3, 2);
cout<<tmp<<endl;
}
*/



/*
void main()
{
	string s("HelxoBit.");  //15
	string sub("Bi");
	size_t index = s.find("xo", 3, 1);
	index = s.find('H', 0);
	index = s.find("xo");
	index = s.rfind('x');

	index = s.find(sub);
	index = s.find(sub, 6);
	if(index == string::npos) //npos
		cout<<"Error."<<endl;
	else
		cout<<index<<endl;
}
*/



/*
void main()
{
	string s("Hello");  //15
	cout << s.c_str() << endl;  //Hello
	cout<<strlen(s.c_str())<<endl;  //0
}
*/



/*
void main()
{
	string s("Hello");  //15
	string s1("BitWorld.");
	char *str = "Bit.";
	char arr[] = " good!";
	//s.append(s1); //
	//s.append(s1, 3, 5);
	//s.append(str);
	//s.append(str,50);
	//s.append(s1.begin(), s1.end());

	s += '!';
	cout << s << endl;
	s += s1;
	cout<<s<<endl;

}
*/



/*
void main()
{
	string s;
	cout<<s.size()<<endl;
	cout<<s<<endl;
	s.push_back('a');
	cout<<s.size()<<endl;
	cout<<s<<endl;
	s.push_back('b');
	cout<<s.size()<<endl;
	cout<<s<<endl;

	s.pop_back();
	cout<<s.size()<<endl;
	cout<<s<<endl;
}
*/



/*
void main()
{
	string s("Hello");
	cout<<s<<endl;    //1
	for(int i=0; i<s.size(); ++i)
		cout<<s[i];
	cout<<endl;
	string::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;

	string::reverse_iterator rit = s.rbegin();
	while(rit != s.rend())
	{
		cout<<*rit;
		++rit;
	}
	cout<<endl;

	for(auto e : s)
	cout<<e;
	cout<<endl;

	for(int i=0; i<s.size(); ++i)
		cout<<s.at(i);
	cout<<endl;

}
*/




/*
void main()
{
	string s;
	s.reserve(100); ////////
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	for(int i=1; i<=100; ++i)
	{
		s.push_back(i);
		cout << i << ": " << s.capacity() << endl;
	}
}
*/



/*
void main()
{
	string s("Hello");
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;

	s.clear();
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;
}
*/


/*
void main()
{
	string s("Hello");
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s<<endl;

	s.resize(10); //Hello00000
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	cout<<s;
	cout << "end"<<endl;
}
*/


/*
void main()
{
string s;
cout<<s.size()<<endl;
cout<<s.capacity()<<endl;

s.reserve(100);
cout<<s.size()<<endl;
cout<<s.capacity()<<endl;

s.reserve(20);
cout<<s.size()<<endl;
cout<<s.capacity()<<endl;

}
*/




/*
void main()
{
	string s;
	cout <<"s.max_size = "<< s.max_size() << endl;  //4294967294
	cout<<s.size()<<endl;  //0
	cout<<s.capacity()<<endl;  //15

	s.resize(100);
	cout<<s.size()<<endl;  //100
	cout<<s.capacity()<<endl;  //111

	s.resize(10);
	cout<<s.size()<<endl;  //10
	cout<<s.capacity()<<endl;  //111

}
*/



/*
void main()
{
	string s("Hello");
	cout<<s.size()<<endl;
	cout<<s.length()<<endl;
	cout<<s.capacity()<<endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout<<s.empty()<<endl;
}
*/

//string (const string& str, size_t pos, size_t len = npos);
/*
void main()
{
	string s;
	cout << s << endl;
	//char *str = "Hello";
	string s1("Hello");
	cout << s1 << endl;
	string s2(10, 'a');
	cout << s2 << endl;
	string s3(s2);
	cout << s3 << endl;

	string s4(s3, 2, 3);
}
*/