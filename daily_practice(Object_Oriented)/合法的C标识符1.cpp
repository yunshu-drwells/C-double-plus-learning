#include<stdio.h>
#include<string.h>

int main()
{
	char s[100];
	gets(s);
	if( s[0]>='a'&&s[0]<='z'||s[0]=='_'||s[0]>='A'&&s[0]<='Z' ){
		for( int i=0; s[i]!='\0'; i++){
			if( s[i]>='a'&&s[i]<='z'||s[i]=='_'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9' ){
				printf( "YES\n" );
				break; 
			}
			else{
				printf( "NO\n" );
				break;
			}
		}
	}
	else{
		printf( "NO\n" );
	}
}
