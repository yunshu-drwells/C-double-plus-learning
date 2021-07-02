#include<stdio.h>
int main(void){
	int grade;
	printf("Enter grade\n");
	scanf("%d",&grade);
	if(grade=100){
	    puts("Å£±Æ°¡Ð¡ÀÏµÜ"); 
	}
	else if(grade>=90){
		puts("A");
	}
	else if(grade>=80){
		puts("B");
	}
	else if(grade>=70){
		puts("C");
	}
	else if(grade>=60){
		puts("D");
	}
	else{
		puts("Éµ±Æ");
	}
}
