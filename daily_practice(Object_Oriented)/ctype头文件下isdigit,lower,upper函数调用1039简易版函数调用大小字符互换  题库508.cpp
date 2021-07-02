#include <stdio.h>
#include <ctype.h>//包含 isdigit  isalpha（lower，upper） 
int main()
{
	char a[100];
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(isdigit(a[i])) printf("%c",a[i]);            //判断是不是数字 
		if(isalpha(a[i]))	//判断是不是字母 
		{
			if(islower(a[i]))printf("%c",toupper(a[i]));//islower判断是不是小写字母，toupper将小写字母改为大写字母 
			if(isupper(a[i]))printf("%c",tolower(a[i]));//isupper判断是不是大写字母，tolower将写字母改为小写字母
		}
	}		
}
