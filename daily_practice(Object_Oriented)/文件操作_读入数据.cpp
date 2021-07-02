#include <stdio.h>
struct Student
{
	int id;        //ID
	char gender;   //性别
	char name[16]; //年龄
};
//存储数据
int save()
{
	const char* filename = "D:\\file 'rb'.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	Student someone = {20150101,'M',"Noral"};
	fwrite(&someone.id,    1,4,fp);
	fwrite(&someone.gender,1,1,fp);
	fwrite(&someone.name,  1,sizeof(someone.name),fp);
	fclose(fp);
	return 0;
}
//读取数据 
int load()
{
	const char* filename = "D:\\file 'rb'.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

//定义一个128字节的缓冲区
	//char buf[128];
	//int n = fread(buf,1,128,fp);
	//printf("n = %d",n);

//顺序读取
	char buf[4];
	while(! feof (fp))
	{
		int n = fread (buf ,1,4,fp);
		if(n > 0 )
		{
			printf("Read %d bytes \n",n);
		}
	}
	//观察返回值n的值 实际读取到的字节个数 此例子n = 21
	//观察buf里的数据  

	fclose(fp);
	return 0;
}
int main()
{
	//save();
	load();
	return 0;
}
/*

(1)打开文件 ：fopen 得到FILE*
const char* filename = "D:\\ file 'rb'";
FILE* fp = fopen(filename ,"rb");
if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
模式为"rb"  (read, binary)  //必须是"rb"，不然会出错
(2)读取数据 ：fread ...
(3)关闭文件 ：fclose

读取数据函数
size_t fread(void *buf size,size_t nelem,FILE* stream);
返回值 ： 实际读取到的字节个数

//顺序读取
如果文件过大，则无法一次读完，可以采用顺序读入，
每次读取一定长度，直到读取。
char buf[4]
while(! feof (fp))
{
	int n = fread (buf ,1,4,fp);
	if(n > 0 )
	{
		printf("Read %d bytes \n",n);
	}
}
注：使用feof函数检验文件是否已经到达末尾（EOF，End of File）
*/
