#include <stdio.h>
struct Student
{
	int id;        //ID
	char gender;   //ÐÔ±ð
	char name[16]; //ÄêÁä
};
int main()
{
	const char* filename = "D:\\struct.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	Student someone = {20150101,'M',"Noral"};
	fwrite(&someone,1,sizeof(someone),fp);

	fclose(fp);
	return 0;
}