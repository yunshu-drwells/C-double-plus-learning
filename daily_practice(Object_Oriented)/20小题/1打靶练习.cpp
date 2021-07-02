#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j;
	int x = 5,y = 10;
	char input;
	int isFire=0;
	
	int ny = 5;
	int iskilled = 0;
	
	while(1)
	{
		system("cls");
		
		if(iskilled == 0)
		{
			for(j = 0;j < ny; j++)
			printf(" ");
			printf(" +\n");
		}
		
		if(isFire==0)
		{
			for(i=0;i<x;i++)
			printf("\n");
		}
		else
		{
			for(i=0;i<x;i++)
			{
				for(j=0;j<y;j++)
				printf(" ");
				printf("  |\n");
			}
			if(y + 2 == ny)
			iskilled  = 1;
			isFire=0;	
		}
		
		for(j=0;j<y;j++)
		printf(" ");
		printf("  *\n");
		for(j=0;j<y;j++)
		printf(" ");
		printf("*****\n");
		for(j=0;j<y;j++)
		printf(" ");
		printf(" * *");
		
		if(kbhit())
		{
			input=getch();
			if(input == 'w') x--;
			if(input == 'a') y--;
			if(input == 's') x++;
			if(input == 'd') y++;
			if(input == ' ') isFire=1;
		}	
	}
return 0; 
}
