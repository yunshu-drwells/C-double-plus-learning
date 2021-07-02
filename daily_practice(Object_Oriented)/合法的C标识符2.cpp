# include <stdio.h>
# include <string.h>
int main (void)
{
	char a[100];
	gets(a);
	
	int len=strlen(a);
	if(a[0]<='z'&&a[0]>='a'||a[0]<='Z'&&a[0]>='A'||a[0]=='_'){
		for(int i=1;i<len;i++){
			if(a[i]<='z'&&a[i]>='a'||a[i]<='Z'&&a[i]>='A'||a[i]=='_'||a[i]<='9'&&a[i]>='0'){
				continue;
			}
			else{
				printf("NO");break;
			}
			printf("YES");
		}
	}
	else{
		printf("NO");
	}
}

