#include <iostream>
using namespace std;



//int firstUniqChar(string& s)
//{
//	if (s.empty()) return -1;
//	if (s.size() == 1) return 0;
//	int j = 0;
//	for (int i = 0; i < s.size() - 1; i++)
//	{
//		for (j = s.size() - 1; j >= i; --j)
//		{
//			if (j == i && s[j] == s[i])
//				return i;
//			if (s[j] == s[i]) break;
//		}
//	}
//	return -1;
//}


int firstUniqChar(string& s)
{
	int freq[26] = { 0 };

	for (int i = 0; i < s.length(); i++)
		freq[s[i] - 'a']++;

	for (int i = 0; i < s.length(); i++)
		if (freq[s[i] - 'a'] == 1)
			return i;
	return -1;
}


int main()
{
	string s("loveleetcode");
	int ret = firstUniqChar(s);
	return 0;
}