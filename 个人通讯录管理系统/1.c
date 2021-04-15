#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

int display()
{
	int i;
	FILE *readfile;
	contact a;

	readfile = fopen("D:\\contact.rec", "rb");				//二进制方式读文件
	if (!readfile)
	{
		printf("联系人文件可能不在指定路径下！\n\n");
		return 0;
	}

	printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
	fread(&a, sizeof(contact), 1, readfile);
	for (i = 1; (i <= 10) && (!feof(readfile)); i++)			//一面显示10条信息
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a.name, a.units, a.tel, a.mob, a.email, a.qq, a.kind);
		fread(&a, sizeof(contact), 1, readfile);
		if (i == 10)
		{
			while (1)					//10条之后提示是否换下一页
			{
				fflush(stdin);
				printf("输入 0 以浏览剩余联系人信息，输入 1 结束联系人信息的浏览：");
				scanf("%d", &i);
				if (i == 0 || i == 1)
					break;
			}
			if (i == 1)
				break;
			if (i == 0)
			{
				system("cls");
				printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
				continue;
			}
		}
	}
	if (feof(readfile))
		printf("\n已显示所有联系人信息\n");

	fclose(readfile);
	return 0;
}