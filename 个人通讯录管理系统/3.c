#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contacts.h"

int search()
{
	char find[50];					//定义要查找的信息
	int  i;

	FILE *readfile;
	contact a;

L2:	readfile = fopen("D:\\contact.rec", "rb");				//二进制方式读文件
	if (!readfile)
	{
		printf("联系人文件可能不在指定路径下！\n\n");
		return 0;
	}

	printf("请输入 名字 以查找的信息：	");				//输入
	fflush(stdin);
	scanf("%s", &find);

	while (1)
	{
		fread(&a, sizeof(contact), 1, readfile);
		if (strcmp(a.name, find) == 0)					//若找到输出全部信息
		{
			printf("\n你所查找的信息如下：\n");
			printf("*******************\n");
			printf("姓    名：%s\n", &a.name);
			printf("单    位：%s\n", &a.units);
			printf("固定电话：%s\n", &a.tel);
			printf("移动电话：%s\n", &a.mob);
			printf("电子邮箱：%s\n", &a.email);
			printf("Q    Q号：%s\n", &a.qq);
			printf("联系人类别：%s\n", a.kind);
			printf("*******************\n");
			break;
		}

		else if (feof(readfile))
		{
			printf("未能找到你需要的信息！\n\n");			//未找到报错
			break;
		}
	}

	while (1)
	{
		i = 0;
		printf("请输入 1 以继续查找，或按其他键以退出该功能：	");
		fflush(stdin);
		scanf("%d", &i);
		printf("\n");
		if (i != 1)
			break;
		else
			goto L2;
	}
	return 0;
}