#include <iostream>
#include<string>
using namespace std;

int LastWordLength(string str)
{
	int count = 0;
	string::iterator it = str.end()-1;
	while (*it != ' '&& it != str.begin())   
		it--;
	if (it == str.begin())
		return str.size();
	while (it+1 != str.end())
	{
		it++; count++;
	}
	return count;
}


int main()
{
	string str("hello");
	//getline(cin, str);
	cout << LastWordLength(str) << endl;
	return 0;
}