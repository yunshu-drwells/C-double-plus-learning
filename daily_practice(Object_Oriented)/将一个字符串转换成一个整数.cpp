#include <iostream>
using namespace std;




//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0
//int StrToInt(string str)
//{
//	if (str.empty()) return 0;
//	long long radix = 1, num = 0;
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend())
//	{
//		if ((*it != '+' && *it != '-') && (*it <= '0' || *it >= '9'))
//			return 0;
//		if (*it != '+' && *it != '-')
//			num += (*it - 48) * radix;
//		radix *= 10;
//		if (it + 1 == str.rend() && *it == '-')
//			num *= -1;
//		it++;
//	}
//	return num;
//}

int StrToInt(string str)
{
	int flag = 1;
	int num = 0;
	int radix = 1;
	if (str.empty()) return 0;
	string::reverse_iterator it = str.rbegin();

	while (it != str.rend())
	{
		if (it + 1 == str.rend())
		{
			if (*it == '+') break;
			if (*it == '-') {flag = -1; break;}
		}
		if (it != str.rend() && *it <= '0' || *it >= '9') return 0;
		num += (*it - '0') * radix;
		radix *= 10;
		it++;
	}
	return num * flag;
}
int main()
{
	int ret = 0;
	string str("+2147483647");
	ret = StrToInt(str);
	return 0;
}
