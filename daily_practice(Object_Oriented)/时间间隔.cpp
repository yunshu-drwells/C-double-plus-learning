#include <stdio.h>
int main (void)
{
	int a,b,c,x,y,z,t1,t2,time;
	scanf("%d:%d:%d",&a,&b,&c);
	scanf("%d:%d:%d",&x,&y,&z);
	t1=a*3600+b*60+c;
	t2=x*3600+y*60+z;
	if(t1>t2){
		time=t1-t2;
	}
	else{
		time=t2-t1;
	}
	printf("%02d:%02d:%02d",time/3600,time/60%60,time%60);
}
