//string类模拟实现
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
	String()
	{
		//m_data = (char*)malloc(1);    //string类型变量的默认初始值是为null,所以不开辟空间也无可厚非
	}
	String(const char* str)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(m_data, str);
	}

	String(const String& s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;

		free(m_data);

		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		strcpy(m_data, s.m_data);

		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char* m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}





/*
//string类模拟实现--构造函数改进1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char *str = nullptr)
	{
		if(str == nullptr)
		{
			m_data = (char*)malloc(sizeof(char));
			m_data[0] = '\0';
		}
		else
		{
			m_data = (char *)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(m_data, str);
		}
	}

	String(const String &s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data)+1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this == &s)
			return *this;

		free(m_data);

		m_data = (char*)malloc(sizeof(char)*(strlen(s.m_data)+1));
		strcpy(m_data, s.m_data);

		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/




/*
//string类模拟实现--构造函数改进2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char *str = "")    //设默认值
	{
		m_data = (char *)malloc(sizeof(char)*(strlen(str)+1));
		if (m_data != nullptr)
			strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data)+1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			free(m_data);
			m_data = (char*)malloc(sizeof(char)*(strlen(s.m_data) + 1));
			if (m_data != nullptr)
				strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/




/*/
//string类模拟实现--构造函数改进3(使用C++中的new和delete进行动态内存管理)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}
private:
	char* m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/
