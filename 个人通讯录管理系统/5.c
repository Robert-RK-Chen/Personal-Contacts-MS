#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"


int delete()
{
	int i, n, j = 1;                                           //i为结构体输出时索引，j为结构体写入时索引，n储存用户输入数字
	contact a[11];                                             //结构体索引从1~10储存文件中的数据
	FILE*readfile;
	FILE*writefile;

	readfile = fopen("D:\\contact.rec", "rb");
	if (!readfile)
	{
		printf("联系人文件可能不在指定路径下！\n");
		exit(1);
	}
	writefile = fopen("D:\\contacts.rec", "wb");
	if (!writefile)
	{
		printf("新的联系人文件可能不在指定路径下！\n");
		exit(1);
	}

	printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
	fread(&a[1], sizeof(contact), 1, readfile);
	for (i = 1; (i <= 10) && (!feof(readfile)); i++)
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a[i].name, a[i].units, a[i].tel, a[i].mob, a[i].email, a[i].qq, a[i].kind);

		while (i == 10)                                              //非最后一页的处理
		{
			n = 100;
			printf("请输入要删除的联系人的序列（1~%d）、输入 0 退出该功能或输入 11 以显示下一页：	", i);
			fflush(stdin);
			scanf("%d", &n);
			if (n > i + 1)
			{
				printf("您输入的信息可能有错误，请重试！\n");
				continue;
			}

			if (0 < n&&n <10)
			{
				for (; j < n; j++)                                   //写入到索引为n-1为止
				{
					fwrite(&a[j], sizeof(contact), 1, writefile);
				}
				j = n + 1;                                             //使下一次从索引从n+1开始写入
				printf("\n已删除该联系人\n\n");
				continue;
			}

			if (n == 11 || n == 10)
			{
				for (; j < n; j++)
					fwrite(&a[j], sizeof(contact), 1, writefile);
				system("cls");
				printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
				i = 0;                                               //为i赋值，使显示器能够继续按1~10读出
				j = 1;                                               //使写入文件从结构体的第一个写入
				break;
			}

			if (n == 0)                                              //退出while的循环
			{
				break;
			}
		}

		if (n == 0)
		{

			for (n = 11; j < n; j++)                                 //将这一页剩余数据写入
				fwrite(&a[j], sizeof(contact), 1, writefile);

			fread(&a[0], sizeof(contact), 1, readfile);              //将为文件中剩余数据写入
			while (!feof(readfile))
			{
				fwrite(&a[0], sizeof(contact), 1, writefile);
				fread(&a[0], sizeof(contact), 1, readfile);
			}
			break;
		}

		fread(&a[i + 1], sizeof(contact), 1, readfile);

		while (feof(readfile))                                       //最后一页的处理
		{
			fflush(stdin);
			printf("\n请输入要删除的联系人的序列（1~%d）、输入 0 退出该功能或输入 11 以显示下一页：	", i);
			scanf("%d", &n);
			if (n > i)
			{
				printf("您输入的信息可能有错误，请重试！\n");
				continue;
			}

			if (0 < n&&n < i)
			{
				for (; j < n; j++)
				{
					fwrite(&a[j], sizeof(contact), 1, writefile);
				}
				printf("\n已删除该联系人\n");
				j = n + 1;
				continue;
			}

			if (n == i || n == 0)
			{
				if (n == 0)                                          //使得n=0与n=i都能使用
					n = i + 1;

				for (; j < n; j++)
					fwrite(&a[j], sizeof(contact), 1, writefile);
				break;
			}
		}
	}

	fclose(readfile);
	fclose(writefile);
	remove("D:\\contact.rec");                                       //删除文件夹
	rename("D:\\contacts.rec", "D:\\contact.rec");                   //修改文件夹名称
	return 0;
}