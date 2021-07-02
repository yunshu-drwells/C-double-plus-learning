#include <stdio.h>
int main (void)
{
	int a[4];
	for(int i=0;i<4;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<3;i++){
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(i!=x&&i!=y&&x!=y){
					printf("%d %d %d\n",a[i],a[x],a[y]);
				}
			}
		}
	} 
	int b[3]={a[0],a[1],a[3]};
	for(int i=0;i<3;i++){
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(i!=x&&i!=y&&x!=y){
					printf("%d %d %d\n",b[i],b[x],b[y]);
				}
			}
		}
	} 
	int c[3]={a[0],a[2],a[3]};
	for(int i=0;i<3;i++){
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(i!=x&&i!=y&&x!=y){
					printf("%d %d %d\n",c[i],c[x],c[y]);
				}
			}
		}
	} 
	int d[3]={a[1],a[2],a[3]};
	for(int i=0;i<3;i++){
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(i!=x&&i!=y&&x!=y){
					printf("%d %d %d\n",d[i],d[x],d[y]);
				}
			}
		}
	} 
 } 
