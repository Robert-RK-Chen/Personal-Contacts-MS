#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contacts.h"

int alter()
{
	int i, j, k;
	char toalter[20];
	FILE *readfile;
	FILE *writefile;
	contact a;

L2:	readfile = fopen("D:\\contact.rec", "rb");				//二进制方式读文件
	if (!readfile)
	{
		printf("您所查找的文件可能不存在！\n\n");
		return 0;
	}

	printf("序号\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tQQ\t\tkind\n\n");
	fread(&a, sizeof(contact), 1, readfile);
	for (i = 1; (!feof(readfile)); i++)			//显示所有联系人信息
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a.name, a.units, a.tel, a.mob, a.email, a.qq, a.kind);
		fread(&a, sizeof(contact), 1, readfile);
	}
	if (feof(readfile))
		printf("您的联系人已显示完毕！\n");
	fclose(readfile);

	readfile = fopen("D:\\contact.rec", "rb");
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

	printf("请输入你想要修改的联系人的姓名：	");
	fflush(stdin);
	scanf("%s", &toalter);

	fread(&a, sizeof(contact), 1, readfile);
	while (!feof(readfile))
	{
		if (strcmp(a.name, toalter) == 0)					//若找到输出全部信息
		{
			printf("*********************************\n输入1 修改联系人姓名；\n输入2 修改联系人单位；\n输入3 修改联系人固定电话\n输入4 修改联系人移动电话；\n输入5 修改联系人电子邮箱；\n输入6 修改联系人QQ号；\n输入7 修改联系人类别。\n*********************************\n");
			printf("请输入数字以修改该联系人相应的信息：	");
			fflush(stdin);
			scanf("%d", &j);
L4:			fflush(stdin);
			switch (j)
			{
			case 1:
				printf("请输入新的联系人名称:	");
				gets(a.name);
				break;
			case 2:
				printf("请输入新的联系人单位:	");
				gets(a.units);
				break;
			case 3:
				printf("请输入新的联系人固定电话:	");
				gets(a.tel);
				break;
			case 4:
				printf("请输入新的联系人移动电话:	");
				gets(a.mob);
				break;
			case 5:
				printf("请输入新的联系人的电子邮箱:	");
				gets(a.email);
				break;
			case 6:
				printf("请输入新的联系人的QQ号:	");
				gets(a.qq);
				break;
			case 7:
				printf("请输入新的联系人的类别:	");
				gets(a.kind);
				break;
			default:
				printf("输入错误！\n");
				break;
			}
			printf("已保存新的联系人信息，输入 1-7 以修改其他信息或输入 0 退出：	");
			fflush(stdin);
			scanf("%d", &j);
			if (j == 0)
				goto L5;
			else
				goto L4;

L5:			while (!feof(readfile))
			{
				fwrite(&a, sizeof(contact), 1, writefile);
				fread(&a, sizeof(contact), 1, readfile);
			}
			break;
		}

		fwrite(&a, sizeof(contact), 1, writefile);
		fread(&a, sizeof(contact), 1, readfile);

		if (feof(readfile))
		{
			printf("未能找到你需要的信息！\n\n");			//未找到报错
			break;
		}
	}

	fclose(writefile);
	fclose(readfile);

	remove("D:\\contact.rec");
	rename("D:\\contacts.rec", "D:\\contact.rec");

	while (1)
	{
		k = 0;
		printf("\n请输入 1 以继续查找，或按其他键以退出该功能：	");
		fflush(stdin);
		scanf("%d", &k);
		printf("\n");
		if (k != 1)
			break;
		else
		{
			system("cls");
			goto L2;
		}
	}
	return 0;
}