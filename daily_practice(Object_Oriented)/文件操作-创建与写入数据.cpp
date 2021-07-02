#include <stdio.h>


int main()
{
const char* filename = "D:\\hell.txt";
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
	printf("failed to open file!\n");
	return -1;
}

char buf[] = "hello world !";
fwrite(buf,1,13,fp);

int a = 0x12345678;
fwrite(&a,1,4,fp);

fclose(fp);

return 0;
}

//fopen打开文件
/*
FILE *fopen(const char *filename,const char *mode);  mode: 使用"wb"(w表示write,b表示binary)
返回值：文件指针-> FILE * 
全路径  (1)c:\\abc.txt   (2)c:/0/abc.txt
示例：

const char* filename = "c:/0/abc.txt";
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
printf("failed to open file!\n");
return -1;
}

*/
//fclose关闭文件
/*
int fclose(FILE* stream);
参数： stream 就是前面fopen的返回值
示例：

fopen(fp);

*/
//写入数据
/*
size_t fwrite(const void* buf,size_t size,size_t count,FILE* stream);
参数：
buf 要写入的数据
size 总是传1
count 所传数据的字节数
stream 就是前面fopen的返回值
返回值：字节数
*/





