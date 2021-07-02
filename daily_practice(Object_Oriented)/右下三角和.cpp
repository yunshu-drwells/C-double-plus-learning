/*--------------------------------------------------

题目：用函数求一个N阶方阵右下三角元素的和（包括副
      对角线上的元素）。    

------------------------------------------------*/
#include <stdio.h>
#define N 3

int sum(int a[][N])
{
  /**********Program**********/
  int y=0;
  for(int i=0;i<N;i++)
  {
    for(int j=N-1-i;j<N;j++)
    {
        y+=a[i][j];
    }
  }
  return (y);
  /**********  End  **********/
}

main()
{
  int a[N][N],i,j;
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      scanf("%d",&a[i][j]);
    }
    
  }

  printf("sum=%5d\n",sum(a));
 
}
