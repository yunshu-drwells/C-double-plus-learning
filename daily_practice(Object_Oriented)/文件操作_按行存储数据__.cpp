#include <iostream>
#include <string.h>
//#define bug
using namespace std;

int save()
{
	const char* filename = "D:\\data_storage_format.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}
#ifdef bug
//按行存储(sprintf)
	char ip[] = "192.168.1.100";
	int port = 8080;

	char line[256];
	sprintf(line,"ip = %s\n",ip);
	fwrite(line,1,strlen(line),fp);

	sprintf(line,"port = %d\n",port);
	fwrite(line,1,strlen(line),fp);
#endif
//按行存储(fprintf)
#ifndef bug
	char ip[] = "192.168.1.100";
	int port = 8081;

	fprintf(fp,"ip = %s\n",ip);
	fprintf(fp,"port = %d\n",port);

#endif
	fclose(fp);
	return 0;
}
//读取数据 
int load()
{
	const char* filename = "D:\\data_storage_format.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

//按行数据的读取
	char buf[512];
	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		if(line)
		{
			printf("got: %s",line);
		}
	}

	fclose(fp);
	return 0;
}
int main()
{
	char line[] = "id  = 123,name = shaofa,hometown = anhui";

	int id;
	char name[32];
	char hometown[32];
	sscanf(line,"id = %d,name = %s,hometown = &s", 
		&id,name,hometown);     //按行解析，一般用sscanf是无法胜任的
							    //sscanf只适合提取数字，不能提取字符串
	save();                     
	load(); 
	return 0;
}
/*


以文本形式存储

当数据量比较小时,可以用文本形式存储。就是把所有数据
均格式化成字符串来存储
通常配置文件是以文本形式存储的,例如*xml,cfg*.ini
 
比如,在xm1文件中存储ip和端口号
<?xml version=1.0" encoding=gb2312 ?>
〈Root>
	くip>192.168.10.60〈/ip》
	くport〉8080く/port〉
</root>


按行存储(sprintf)
把每个单元的数据格式化为一行（末尾加上/n）,写入文件

	例如，保存ip和port
	char ip[] = "192.168.1.100";
	int port = 8080;

	char line[256];
	sprintf(line,"ip = %s\n,ip");
	fwrite(line,1,strlen(line),fp);

	sprintf(line,"port = %d\n",port);
	fwrite(line,1,strlen(line),fp);


按行存储(fprintf)
也可以直接使用fprintf函数
	char ip[] = "192.168.1.100";
	int port = 8081;

	fprintf(fp,"ip = %s\n",ip);
	fprintf(fp,"port = %d\n,port");

	fprintf：第一个参数是文件指针，后面的参数和printf
	直接将数据格式化成字符串并写入文件
	缺点：解析时复杂度相对较高
	由于不知道每行长度是多长，所以用fread读取时，需要检测是否
	已经读到\n这个分隔符（有点复杂啊）

	推荐使用fgets函数,这个函数已经把上面的逻辑给封装好了。
	fgets内部会检查，当读到字符\n时，停止读取。返回实际
	读取的字节长度。
*/