//先看memcpy的使用问题
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s) :m_data(nullptr)
	{
		String tmp(s.m_data);
		swap(m_data, tmp.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s);
			swap(m_data, tmp.m_data);
		}
		return *this;
	}
	~String()
	{
		if (m_data)
		{
			delete[]m_data;
			m_data = NULL;
		}
	}
private:
	char* m_data;
};


template<typename T>
void Copy(T* dst, const T* src, size_t sz)
{
	memcpy(dst, src, sizeof(T) * sz); 
	//直接对对象memcpy只是拷贝了对象数据成员的指针
	//(是一种浅拷贝,这样会造成很大的问题,对象析构时指向同一快内存空间的数据会多次析构就会出问题)
}


int main()
{
	int ar1[5] = { 11,22,33,44,55 };
	int ar2[5];
	Copy(ar2, ar1, 5);

	String sa1[3] = { "aa", "bb", "cc" };
	String sa2[3];
	Copy(sa2, sa1, 3);

	return 0;
}





/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s) :m_data(nullptr)
	{
		String tmp(s.m_data);
		swap(m_data, tmp.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s);
			swap(m_data, tmp.m_data);
		}
		return *this;
	}
	~String()
	{
		if (m_data)
		{
			delete[]m_data;
			m_data = NULL;
		}
	}
private:
	char* m_data;
};


//通用
template<typename T>
void Copy(T * dst, const T * src, size_t sz, bool IsPOD)
{
	//cout<<typeid(T).name()<<endl;
	//bool IsPOD = IsPODType(typeid(T).name());
	if (IsPOD)
		memcpy(dst, src, sizeof(T) * sz);
	else
	{
		for (size_t i = 0; i < sz; ++i)
		{
			dst[i] = src[i];
		}
	}
}

bool IsPODType(const char* type)
{
	const char* type_ar[] = {
								"bool",
								"short",
								"int",
								"float",
								"long",
								"double",
								"long long"
	};
	int n = sizeof(type_ar) / sizeof(const char*);
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(type, type_ar[i]) == 0)
			return true;
	}
	return false;
}

int main()
{
	int ar1[5] = { 11,22,33,44,55 };
	int ar2[5];
	Copy(ar2, ar1, 5, IsPODType("int"));

	String sa1[3] = { "aa", "bb", "cc" };
	String sa2[3];
	Copy(sa2, sa1, 3, IsPODType("String"));
	return 0;
}
*/




/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s) :m_data(nullptr)
	{
		String tmp(s.m_data);
		swap(m_data, tmp.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s);
			swap(m_data, tmp.m_data);
		}
		return *this;
	}
	~String()
	{
		if (m_data)
		{
			delete[]m_data;
			m_data = NULL;
		}
	}
private:
	char* m_data;
};

class Test
{
public:
	Test(int d = 0) : m_data(d)
	{}
private:
	int m_data;
};


struct __true_type
{};
struct __false_type
{};


template<class T>
struct type_traits
{
	typedef __false_type IsPODType;  //类型的萃取
};

template<>
struct type_traits<int>
{
	typedef __true_type IsPODType; //
};

template<>
struct type_traits<Test>
{
	typedef __true_type IsPODType; //
};

////////////////////////////////////////////////////////////////
template<typename T>
void _Copy(T* dst, const T* src, size_t sz, __true_type)
{
	memcpy(dst, src, sizeof(T) * sz);
}
template<typename T>
void _Copy(T* dst, const T* src, size_t sz, __false_type)
{
	for (int i = 0; i < sz; ++i)
	{
		dst[i] = src[i];
	}
}

//通用Copy方法
template<typename T>
void Copy(T* dst, const T* src, size_t sz)
{
	//类型萃取
	typedef type_traits<T>::IsPODType IsPOD;
	_Copy(dst, src, sz, IsPOD());  //__true_type()
}


void main()
{
	int ar1[5] = { 11,22,33,44,55 };
	int ar2[5];
	Copy(ar2, ar1, 5);

	String sa1[3] = { "aa", "bb", "cc" };
	String sa2[3];
	Copy(sa2, sa1, 3);

	Test st1[3] = { 10,20,30 };
	Test st2[3];
	Copy(st2, st1, 3);
}
*/

