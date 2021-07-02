 #include<stdio.h>
 int main(void)
 {
 	int n=0;
 	printf("input a string");
 	loop:if(getchar()!=' '){
 		n++;
 		goto loop;
	 }
	 printf("%d",n);
}
