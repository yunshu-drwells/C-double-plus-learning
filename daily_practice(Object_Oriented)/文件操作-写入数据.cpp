#include <stdio.h>
#include <string.h>
//#define bug
//定义结构体
struct Student
{
	int id;        //ID
	char gender;   //性别
	char name[16]; //年龄
};
int main()
{
//打开文件
const char* filename = "D:\\hell2.txt";   // 或者  "D:/hell2.txt"
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
	printf("failed to open file!\n");
	return -1;
}

int buf[4] = { 0xA001,0xB002,0xC003,0XD004};

#ifdef bug
fwrite(buf,1,sizeof(buf),fp); //方法1（按字节写入)
#endif

#ifndef bug
for(int i=0;i<4;i++)            //方法2
{
	char text[16];
	sprintf(text,"%d,",buf[i]);   //将数字格式化成一个字符串，再将字符串写入文件
 	fwrite(text,1,strlen(text),fp);
	printf("i = %d  strlen_of_buf[i]%d\n",i,strlen(text));
	printf("\n\n");
}
#endif

printf("%d\n",sizeof(buf));

//写入浮点数 法（2）
double a  = 4/3.0;
char text[16];
sprintf(text,"%.13f",a);  //此例只能保存到小数点后13位即text[n]的n-1个；
fwrite(text,1,strlen(text),fp);
printf("strlen_of_double_a %d\n",strlen(text));
printf("\n\n");

//写入浮点数 法（1）
double b = 3 / 4.0;
fwrite(&b,1,sizeof(b),fp);

//写入字符串“hello”
char buf_[] = "hello";
fwrite(buf,1,strlen(buf_),fp);

//创建结构体的对象
Student someone = {20150101,'M',"Noral"};

//结构体数据的写入

//(1)整体写入法
#ifdef bug
fwrite(&someone,1,sizeof(someone),fp);
#endif

//(2)将各字段分开写
#ifndef bug
fwrite(&someone.id,    1,4,fp);
fwrite(&someone.gender,1,1,fp);
fwrite(&someone.name,  1,sizeof(someone.name),fp);
#endif

//关闭文件
fclose(fp);

return 0;
}
/*
*******************
//fopen打开文件
*******************

FILE *fopen(const char *filename,const char *mode);  
mode: 使用"wb"(w表示write ,b表示binary) == 覆盖写入 每次打开文件都清空原有内容，即使不写入新内容，也会被清理
mode: 使用"ab"(a表示append,b表示binary) == 追加写入 每次打开文件不清空原有内容，新内容追加在末尾
fopen返回NULL的情况 <1>目录不存在啊 <2>存在但只读方式的文件以"wb"方式打开
返回值：文件指针-> FILE * 
全路径  (1)c:\\abc.txt  （注意使用反斜杠的时候  是转义字符“\\”） (2)c:/0/abc.txt
路径文件名 <1> 后缀可以随意写  eg: text.dat \ text.data \ text.mydata123   <2> 甚至没有后缀名也可以

示例：

const char* filename = "c:/0/abc.txt";
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
printf("failed to open file!\n");
return -1;
}

*/
/*
*******************
//fclose关闭文件
*******************
/*
int fclose(FILE* stream);
参数： stream 就是前面fopen的返回值
示例: fopen(fp);

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
/*

*******************
//写入整形数据
*******************
*/
/*
有一个int 数组，在存储文件时，一般有两种形式
int buf[4] = { 0xA001,0xB002,0xC003,0XD004};

方法1（按字节写入）：直接按字节输入
	fwrite(buf,1,sizeof(buf),fp);
	(对照VS的内存窗口来理解）

方法2：格式化为字符串写入
for(int i=0;i<4;i++)
{
	char text[16];
	sprintf(text,"%d,",buf[i]);  //格式化为字符串写入,每个数字中间加一个逗号
	fwrite(test,1,strlen(test),fp);
}
sprintf-> n. 把格式数据写成串（函数指令）

*******************
对于浮点数（float,double),也可以使用这两种写法
*******************
（1）
double a = 3 / 4.0;
fwrite(&a,1,sizeof(a),fp);

（2）方法2容易丢失数据
double a  = 4/3.0;
char text[16];
sprintf(text,"%.13f",a); 
fwrite(text,1,strlen(text),fp);

*******************
写入字符串
*******************
（1）按实际长度写入
char buf[] = "hello";
fwrite(buf,1,strlen(buf),fp);

(2) 按固定长度写入
char buf[16] = "hello";
fwrite(buf,1,16,fp);

*******************
结构体数据的写入
*******************

(1)整体写入法
struct Student
{
	int id;        //ID
	char gender;   //性别
	char name[16]; //年龄
}
Student someone = {20150101,'M',"Noral"};

fwrite(&someone,1,sizeof(someone),fp);

（2）将各字段分开写
struct Student
{
	int id;        //ID
	char gender;   //性别
	char name[16]; //年龄
}

Student someone = {20150101,'M',"Noral"};

fwrite(&someone.id,    1,4,fp);
fwrite(&someone.gender,1,1,fp);
fwrite(&someone.name,  1,sizeof(someone.name),fp);

*/




