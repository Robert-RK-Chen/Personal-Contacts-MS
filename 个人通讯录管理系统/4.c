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

L2:	readfile = fopen("D:\\contact.rec", "rb");				//�����Ʒ�ʽ���ļ�
	if (!readfile)
	{
		printf("�������ҵ��ļ����ܲ����ڣ�\n\n");
		return 0;
	}

	printf("���\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tQQ\t\tkind\n\n");
	fread(&a, sizeof(contact), 1, readfile);
	for (i = 1; (!feof(readfile)); i++)			//��ʾ������ϵ����Ϣ
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a.name, a.units, a.tel, a.mob, a.email, a.qq, a.kind);
		fread(&a, sizeof(contact), 1, readfile);
	}
	if (feof(readfile))
		printf("������ϵ������ʾ��ϣ�\n");
	fclose(readfile);

	readfile = fopen("D:\\contact.rec", "rb");
	if (!(readfile))
	{
		printf("��ϵ���ļ����ܲ���ָ��·���£�\n");
		exit(1);
	}
	writefile = fopen("D:\\contacts.rec", "wb");
	if (!(writefile))
	{
		printf("��ϵ���ļ����ܲ���ָ��·���£�\n");
		exit(1);
	}

	printf("����������Ҫ�޸ĵ���ϵ�˵�������	");
	fflush(stdin);
	scanf("%s", &toalter);

	fread(&a, sizeof(contact), 1, readfile);
	while (!feof(readfile))
	{
		if (strcmp(a.name, toalter) == 0)					//���ҵ����ȫ����Ϣ
		{
			printf("*********************************\n����1 �޸���ϵ��������\n����2 �޸���ϵ�˵�λ��\n����3 �޸���ϵ�˹̶��绰\n����4 �޸���ϵ���ƶ��绰��\n����5 �޸���ϵ�˵������䣻\n����6 �޸���ϵ��QQ�ţ�\n����7 �޸���ϵ�����\n*********************************\n");
			printf("�������������޸ĸ���ϵ����Ӧ����Ϣ��	");
			fflush(stdin);
			scanf("%d", &j);
L4:			fflush(stdin);
			switch (j)
			{
			case 1:
				printf("�������µ���ϵ������:	");
				gets(a.name);
				break;
			case 2:
				printf("�������µ���ϵ�˵�λ:	");
				gets(a.units);
				break;
			case 3:
				printf("�������µ���ϵ�˹̶��绰:	");
				gets(a.tel);
				break;
			case 4:
				printf("�������µ���ϵ���ƶ��绰:	");
				gets(a.mob);
				break;
			case 5:
				printf("�������µ���ϵ�˵ĵ�������:	");
				gets(a.email);
				break;
			case 6:
				printf("�������µ���ϵ�˵�QQ��:	");
				gets(a.qq);
				break;
			case 7:
				printf("�������µ���ϵ�˵����:	");
				gets(a.kind);
				break;
			default:
				printf("�������\n");
				break;
			}
			printf("�ѱ����µ���ϵ����Ϣ������ 1-7 ���޸�������Ϣ������ 0 �˳���	");
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
			printf("δ���ҵ�����Ҫ����Ϣ��\n\n");			//δ�ҵ�����
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
		printf("\n������ 1 �Լ������ң������������˳��ù��ܣ�	");
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