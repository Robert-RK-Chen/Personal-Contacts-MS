#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

int display()
{
	int i;
	FILE *readfile;
	contact a;

	readfile = fopen("D:\\contact.rec", "rb");				//�����Ʒ�ʽ���ļ�
	if (!readfile)
	{
		printf("��ϵ���ļ����ܲ���ָ��·���£�\n\n");
		return 0;
	}

	printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
	fread(&a, sizeof(contact), 1, readfile);
	for (i = 1; (i <= 10) && (!feof(readfile)); i++)			//һ����ʾ10����Ϣ
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a.name, a.units, a.tel, a.mob, a.email, a.qq, a.kind);
		fread(&a, sizeof(contact), 1, readfile);
		if (i == 10)
		{
			while (1)					//10��֮����ʾ�Ƿ���һҳ
			{
				fflush(stdin);
				printf("���� 0 �����ʣ����ϵ����Ϣ������ 1 ������ϵ����Ϣ�������");
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
		printf("\n����ʾ������ϵ����Ϣ\n");

	fclose(readfile);
	return 0;
}