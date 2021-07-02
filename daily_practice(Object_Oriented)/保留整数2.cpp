#include<stdio.h>
int main()
{
    int i;
    char a[80];
    gets(a);
    for(i = 0;a[i] != '\0';i++)
    {
        if(a[i] >= '0'&&a[i] <= '9')
            printf("%c",a[i]);
        else
        {
            a[i] = '*';
            if(a[i-1] != '*')
                printf("%c",a[i]);
        }
    }
    printf("\n");
    return 0;
}
