
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

/////////////////////////////////////////
//length()
//operator[]
//operator+
//operator+=
//operator > < >= <= == !=
/////////////////////////////////////////
class String
{
public:
	String(const char* str = "")   //常类型到常类型
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}
public:
	int length()const
	{
		return strlen(m_data) + 1;
	}

	char operator[](int i)
	{
		assert(i >= 0 && i < length());
		return m_data[i];
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[](this->m_data);
			new char[strlen(s.m_data) + 1];
			strcpy(this->m_data, s.m_data);
		}
		return *this;
	}

	String operator+(const String& s)
	{
		char* tmp = new char[strlen(this->m_data) + strlen(s.m_data) + 1];
		strcpy(tmp, this->m_data);
		strcat(tmp, s.m_data);

		String temp(tmp);
		delete[]tmp;
		return temp;
	}
	String& operator+=(const String& s)
	{
		int new_size = length() + s.length() + 1;
		char* tmp = new char[new_size];
		strcpy(tmp, m_data);
		strcat(tmp, s.m_data);

		delete[]m_data;
		m_data = tmp;
		return *this;
	}
	/*String& operator+=(const String& s)
	{
	char* tmp = new char[strlen(this->m_data) + strlen(s.m_data) + 1];
	strcpy(tmp, this->m_data);
	strcat(tmp, s.m_data);

	delete[]m_data;
	this->m_data = tmp;
	return *this;
	}*/

public:
	bool operator==(const String& s)
	{
		if (strcmp(this->m_data, s.m_data) == 0)
			return true;
		return false;
	}
	bool operator!=(const String& s)
	{
		if (strcmp(this->m_data, s.m_data) != 0)
			return true;
		return false;
	}
	bool operator>(const String& s)
	{
		if (strcmp(this->m_data, s.m_data) > 0)
			return true;
		return false;
	}
	bool operator<(const String& s)
	{
		if (strcmp(this->m_data, s.m_data) < 0)
			return true;
		return false;
	}
	bool operator>=(const String& s)
	{
		if (strcmp(this->m_data, s.m_data) < 0)
			return false;
		return true;
	}
	bool operator<=(const String& s)
	{
		if (strcmp(this->m_data, s.m_data) > 0)
			return false;
		return true;
	}
private:
	char* m_data;
};

int main()
{
	String s1("Hello"); //s1[0] ==> H
	String s2("Bit.");

	s1 = s2;
	for (int i = 0; i < s1.length(); ++i)
		cout << s1[i];
	cout << endl;


	String s = s1 + s2; //s = HelloBit
	for (int i = 0; i < s.length(); ++i)
		cout << s[i];
	cout << endl;


	s1 += s2;    //

	for (int i = 0; i < s1.length(); ++i)
		cout << s1[i];
	cout << endl;


	if (s1 == s2)
		cout << "s1 == s2" << endl;
	if (s1 != s2)
		cout << "s1 != s2" << endl;
	if (s1 > s2)
		cout << "s1 > s2" << endl;
	if (s1 < s2)
		cout << "s1 < s2" << endl;
	if (s1 >= s2)
		cout << "s1 >= s2" << endl;
	if (s1 <= s2)
		cout << "s1 <= s2" << endl;

	return 0;
}


/*

String& operator+=(const String& s)
{
this->m_data = (char*)realloc(this->m_data, (strlen(m_data) + strlen(s.m_data) + 1));
if (this->m_data != nullptr)
strcat(this->m_data, s.m_data);
return *this;
}

String operator+(const String& s)
{
char* tmp = (char*)malloc(strlen(m_data) + 1);
if (tmp != NULL)
strcpy(tmp, m_data);
(void)realloc(tmp, (strlen(m_data) + strlen(s.m_data) + 1));
if (tmp != NULL)
strcat(tmp, s.m_data);
String temp(tmp);    //*****功能实现正确*****但未释放tmp*****
return temp;
}
*/
  