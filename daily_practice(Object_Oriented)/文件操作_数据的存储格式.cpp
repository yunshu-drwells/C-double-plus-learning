#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //malloc函数
//#define bug;

//定义结构体
	struct Car
	{
		char maker[32]; //制造商
		int price;      //价格
	};
	struct Citizen
	{
		char name[32]; //名字
		int  deposite; //存款
		Car* car;	   //NULL时表示没车
	};
//存储数据 
int save()
{
	const char* filename = "D:\\data_storage_format.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}
/*
	int a = 12345;
	int b = 6789;

	char buf[128];
	sprintf(buf,"%d,%d",a,b); //int整形数据之间以逗号隔开 
	fwrite(buf,1,strlen(buf),fp);
*/

//基本类型的变量的存储
	int a = 0x12345678;
	int b = 0x0A0A0A0A;
	fwrite(&a,1,4,fp);
	fwrite(&b,1,4,fp);

//已知长度的数组的存储
	float arr[4] = {1.1f,1.2f,1.3f,1.4f};
	fwrite(arr,1,4*4,fp);
/*
//未知长度数组的写入
float arr[256];
arr = getchar();               //error
*/

//字符数组的存储
	char text[32] = "shaofa,sdjvjfdvbjrhljh";
	fwrite(text,1,32,fp);
Car* car = (Car*) malloc(sizeof(Car));
	strcpy(car->maker, "Chevrolet");
	car->price = 10; 

//指针的存储
	Citizen who = {"shaofa",100};
	who.car = car;
	
	fwrite(who.name,1,32,fp);
	fwrite(&who.deposite,1,4,fp);
	if(who.car != NULL)
	{
		fwrite("Y",1,1,fp); //存入一个字节‘Y’
		fwrite(who.car->maker,1,32,fp);
		fwrite(&who.car->price,1,4,fp); 
	}
	else
	{
		fwrite("N",1,1,fp); //存入一个字节‘N’
	}
	
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

//定义一个128字节的缓冲区
	//char buf[128];
	//int n = fread(buf,1,128,fp);
	//printf("n = %d",n);

/*
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
*/

//基本类型的变量的读取
	int a,b;
	fread(&a,1,4,fp);
	fread(&b,1,4,fp);
	printf("int read: a = %d,b = %d \n",a,b);

//未知长度数组的读取
#ifdef bug
	//将读取的未知长度的float数组放入arr数组
	float arr[256];
	int count = 0;

	while(! feof(fp))
{
	float a;
	if(fread(&a,1,4,fp) <= 0)
	{
		break;
	}
	printf("string_float read: %.2f \n",a);

	arr[count] = a;//将读取的float数组放入arr数组
	count ++;
}
//打印放入arr数组的float数组
	printf("print_new_float_arr[count]\n");

	for(int j = 0;j<count;j++)
	{
		printf("j = %d,new_float_arr[j] = %.2f\n",j,arr[j]);
	}
#endif

//已知长度数组的读取
#ifndef bug
float acc[4];
fread(acc,1,4*4,fp);
//打印读入acc数组的float数组
	printf("print_new_float_acc[4]\n");
	for(int j = 0;j<4;j++)
	{
		printf("j = %d,new_float_acc[j] = %.2f\n",j,acc[j]);
	}
#endif


//字符数组的读取
	char abc[32];
	//fread (abc,1,32,fp);
	int  n = fread(abc,1,32,fp);
	printf("%d",n);
//打印放入abc数组的字符数组
	printf("print_new_character_abc[i]\n");

	printf("new_character_abc[j]= %s \n",abc);

	for(int j = 0;j<n;j++)
	{
		printf("j = %2d,new_character_acc[j]= %c\n",j,abc[j]);
	}

//指针的读取
Citizen who;
	fread(who.name,1,32,fp);	
	fread(&who.deposite,1,4,fp);
	
	char has = 'N';
	fread(&has,1,1,fp);
	if(has == 'Y')
	{
		Car* car = (Car*) malloc(sizeof(Car));
		fread(car->maker,1,32,fp);
		fread(&car->price,1,4,fp);
		who.car = car;
//		printf("car.maker = %s, car.prince = %d" ,car->maker,car->price);
	}
	else
	{
		who.car = NULL;
	}
/*
printf("who.car.maker = , who.car.prince = , 
who.name = %c,who.deposite = %d",
who.car->maker,who->car->price,who.name,who.deposite);
*/
	fclose(fp);
	return 0;
}
int main()
{
	save();
	load();
	return 0;
}
/*
数据存储的基本原则
能够写入，也能够读出并还原
eg:
失败的存储 两个int变量， ： 12345和6790

失败：
char buf[128];
sprintf("%d%d",a,b);
fwrite(buf,1,strlen(buf),fp);

可行：
char buf[128];
sprintf("%d,%d",a,b); //int整形数据之间以逗号隔开

如果不以逗号隔开，就无法对数据进行解析。数据白存了！

数据存储的格式是不限的，只要你能满足
“能写入，能读出并还原”的原则，哪种方案都可以

************************
最简单的方案：按字节存储
************************
char / short / int : 占1，2，4个字节
float / double : 4，8个字节
数组：
字符串;
指针：另行讨论

（1）基本类型的变量
	char / short / int / float / double型变量的存储
	只需要知道变量的地址和大小

	//写入
	int a = 0x12345678;
	int b = 0x0A0A0A0A;
	fwrite(&a,1,4,fp);
	fwrite(&b,1,4,fp);

	//读取
	int a,b;
	fread(&a,1,4,fp);
	fread(&b,1,4,fp);

（2）数组的存储
	//写入
	地址：数组名
	字节数：手工计算

	<2>已知长度数组的写入
	float arr[4];
	fwrite(arr,1,4*4,fp);

	<1>未知长度数组的写入
	float arr[256];
	arr = getchar();               //error


	//读取
	<1>未知长度数组的读取
	由于不知道一共存储了多少个float,需要循环读取
	while(! feof(fp))
	{
		float a;
		if(fread(&a,1,4,fp) <= 0)
		{
			break;
		}
	}
	<2>已知长度数组的读取

	float acc[4];
	fwrite(acc,1,4*4,fp);


（3）字符数组的存储（一种简单存取方式）
	定长方式存取：不论有效长度是多少，统一存储32个字节

	char text[32];
	fwrite(text,1,32,fp);
	fread (text,1,32,fp);

	字符数组的读取
	char abc[32];
	fread (acc,1,32,fp);
（4）结构体的存储
	<1>直接存取整个结构体
	struct Student
	{
	int id;
	char name[16];
	int scores[3];
	};
	Student s = {201501,"shaofa",{90,90, 90} };
	//写入
	fwrite(&s,1,sizeof(s),fp);
	//读出
	fread (&s,1,sizeof(s),fp);

	<2>把每个成员变量依次存储
	struct Student
	{
	int id;
	char name[16];
	int scores[3];
	};
	Student s = {201501,"shaofa",{90,90, 90} };

	//写入
	fwrite(&s.id,    1,sizeof(s.id),fp);
	fwrite(&s.name,  1,sizeof(s.name),fp);
	fwrite(&s.scores,1,sizeof(s.scores),fp);

	//读出
	fread (&s.id,    1,sizeof(s.id),    fp);
	fread (&s.name,  1,sizeof(s.name),  fp);
	fread (&s.scores,1,sizeof(s.scores),fp);

(5)指针的存储
指针要么不存储，要么存储它指向的对象的内容
（指针本身没有必要存储，它只是一个地址）
struct Car
{
	char maker[32]; //制造商
	int price;      //价格
}；
struct Citizen
{
	char name[32]; //名字
	int  deposite; //存款
	Car& car;	   //NULL时表示没车
}

Car* car = (Car*) malloc(sizeof(Car));
strcpy(car->maker, "Chevrolet");

car->price = 10; 

Citizen who = {"shaofa",100};
who.car = car;



*/












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