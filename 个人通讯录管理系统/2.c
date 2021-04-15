#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

int add()
{
	int i, j, k, n;
	contact a;
	contact b;
	FILE *writefile;
	FILE *readfile;

	readfile = fopen("D:\\contact.rec", "rb");                           //二进制方式读文件
	if (!readfile)
	{
		writefile = fopen("D:\\contact.rec", "ab");
		if (!(writefile))
		{
			printf("联系人文件可能不在指定路径下！\n");
			exit(1);
		}

		while (1)
		{
			fflush(stdin);
			printf("\n请输入你想要添加的人数: ");						     //添加的人数
			scanf("%d", &j);
			if (j >= 0)
				break;
			printf("输入的数字不合规，请重试！\n");
		}

		system("cls");	                                                 //对联系人进行信息添加
		for (k = 1; k <= j; k++)
		{
			printf("*************************************\n");
			printf("请输入 第%d个 联系人的详细信息（共%d个）\n", k, j);
			printf("*************************************\n");
			fflush(stdin);
			printf("name:	");
			gets(a.name);
			printf("units:	");
			gets(a.units);
			printf("tel:	");
			gets(a.tel);
			printf("mobile:	");
			gets(a.mob);
			printf("email:	");
			gets(a.email);
			printf("qq:	");
			gets(a.qq);
			printf("kind:	");
			gets(a.kind);
			fwrite(&a, sizeof(contact), 1, writefile);
		}

		fclose(writefile);
		printf("联系人信息保存成功！\n");

		return 0;
	}

	printf("序号\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tQQ\t\tkind\n\n");
	fread(&a, sizeof(contact), 1, readfile);
	for (i = 1; (!feof(readfile)); i++)			                     //显示所有联系人信息
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a.name, a.units, a.tel, a.mob, a.email, a.qq, a.kind);
		fread(&a, sizeof(contact), 1, readfile);
	}
	if (feof(readfile))
		printf("您的联系人已显示完毕！\n");
	fclose(readfile);

	readfile = fopen("D:\\contact.rec", "rb");                       //修改联系人信息
	if (!(readfile))
	{
		printf("联系人文件可能不在指定路径下！\n");
		exit(1);
	}
	writefile = fopen("D:\\contacts.rec", "wb");
	if (!(writefile))
	{
		printf("联系人文件可能不在指定路径下！\n");
		exit(1);
	}

	printf("需要插入的位置（前面的序号）：   ");                           //插入的位置
	fflush(stdin);
	scanf("%d", &n);
	while (n > i + 1)
	{
		printf("您输入的信息可能有错误，请重试！\n");
		printf("需要插入的位置（前面的序号）：   ");
		fflush(stdin);
		scanf("%d", &n);
	}

	while (1)
	{
		fflush(stdin);
		printf("\n请输入你想要添加的人数: ");						     //添加的人数
		scanf("%d", &j);
		if (j >= 0)
			break;
		printf("输入的数字不合规，请重试！\n");
	}

	fread(&b, sizeof(contact), 1, readfile);                         //选择的位置的前面数据写入
	for (i = 1; i < n; i++)
	{
		fwrite(&b, sizeof(contact), 1, writefile);
		fread(&b, sizeof(contact), 1, readfile);
	}
	system("cls");	                                                 //对联系人进行信息添加
	for (k = 1; k <= j; k++)
	{
		printf("*************************************\n");
		printf("请输入 第%d个 联系人的详细信息（共%d个）\n", k, j);
		printf("*************************************\n");
		fflush(stdin);
		printf("name:	");
		gets(a.name);
		printf("units:	");
		gets(a.units);
		printf("tel:	");
		gets(a.tel);
		printf("mobile:	");
		gets(a.mob);
		printf("email:	");
		gets(a.email);
		printf("qq:	");
		gets(a.qq);
		printf("kind:	");
		gets(a.kind);
		fwrite(&a, sizeof(contact), 1, writefile);
	}
	while (!feof(readfile))                                          //位置后面的数据进行添加
	{
		fwrite(&b, sizeof(contact), 1, writefile);
		fread(&b, sizeof(contact), 1, readfile);
	}

	fclose(readfile);
	fclose(writefile);
	printf("联系人信息保存成功！\n");
	remove("D:\\contact.rec");
	rename("D:\\contacts.rec", "D:\\contact.rec");
	return 0;
}