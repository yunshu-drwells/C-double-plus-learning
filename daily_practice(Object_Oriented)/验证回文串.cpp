//125. 验证回文串
#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s)
{
	if (s.empty()) return true;
	string::iterator Begin = s.begin(), End = s.end() - 1;

	while (Begin != s.end() && *Begin == ' ') Begin++;
	if (Begin == s.end()) return true;
	if (*(Begin - 1) == ' ') return false;

	while (Begin < End && Begin + 1 != End)
	{
		while ((*Begin >= 0 && *Begin <= 47) || (*Begin >= 58 && *Begin <= 64) || (*Begin >= 91 && *Begin <= 96) || *Begin > 'z')
			Begin++;
		while ((*End >= 0 && *End <= 47) || (*End >= 58 && *End <= 64) || (*End >= 91 && *End <= 96) || *End > 'z')
			End--;
		if (*Begin != *End && (*Begin != *End + 32 && *Begin != *End - 32) )
			return false;
		Begin++;
		End--;
	}
	if(*Begin == *End || (*Begin == ' ' || *End == ' ') )
		return true;
	else
		return false;
}

int main()
{
	//string s("race a car");  //A man, a plan, a canal : Panama
	string s("   a");
	//string s;
	cout<<isPalindrome(s)<<endl;
	return 0;
}