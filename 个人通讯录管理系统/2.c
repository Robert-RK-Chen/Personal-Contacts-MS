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

	readfile = fopen("D:\\contact.rec", "rb");                           //�����Ʒ�ʽ���ļ�
	if (!readfile)
	{
		writefile = fopen("D:\\contact.rec", "ab");
		if (!(writefile))
		{
			printf("��ϵ���ļ����ܲ���ָ��·���£�\n");
			exit(1);
		}

		while (1)
		{
			fflush(stdin);
			printf("\n����������Ҫ��ӵ�����: ");						     //��ӵ�����
			scanf("%d", &j);
			if (j >= 0)
				break;
			printf("��������ֲ��Ϲ棬�����ԣ�\n");
		}

		system("cls");	                                                 //����ϵ�˽�����Ϣ���
		for (k = 1; k <= j; k++)
		{
			printf("*************************************\n");
			printf("������ ��%d�� ��ϵ�˵���ϸ��Ϣ����%d����\n", k, j);
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
		printf("��ϵ����Ϣ����ɹ���\n");

		return 0;
	}

	printf("���\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tQQ\t\tkind\n\n");
	fread(&a, sizeof(contact), 1, readfile);
	for (i = 1; (!feof(readfile)); i++)			                     //��ʾ������ϵ����Ϣ
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a.name, a.units, a.tel, a.mob, a.email, a.qq, a.kind);
		fread(&a, sizeof(contact), 1, readfile);
	}
	if (feof(readfile))
		printf("������ϵ������ʾ��ϣ�\n");
	fclose(readfile);

	readfile = fopen("D:\\contact.rec", "rb");                       //�޸���ϵ����Ϣ
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

	printf("��Ҫ�����λ�ã�ǰ�����ţ���   ");                           //�����λ��
	fflush(stdin);
	scanf("%d", &n);
	while (n > i + 1)
	{
		printf("���������Ϣ�����д��������ԣ�\n");
		printf("��Ҫ�����λ�ã�ǰ�����ţ���   ");
		fflush(stdin);
		scanf("%d", &n);
	}

	while (1)
	{
		fflush(stdin);
		printf("\n����������Ҫ��ӵ�����: ");						     //��ӵ�����
		scanf("%d", &j);
		if (j >= 0)
			break;
		printf("��������ֲ��Ϲ棬�����ԣ�\n");
	}

	fread(&b, sizeof(contact), 1, readfile);                         //ѡ���λ�õ�ǰ������д��
	for (i = 1; i < n; i++)
	{
		fwrite(&b, sizeof(contact), 1, writefile);
		fread(&b, sizeof(contact), 1, readfile);
	}
	system("cls");	                                                 //����ϵ�˽�����Ϣ���
	for (k = 1; k <= j; k++)
	{
		printf("*************************************\n");
		printf("������ ��%d�� ��ϵ�˵���ϸ��Ϣ����%d����\n", k, j);
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
	while (!feof(readfile))                                          //λ�ú�������ݽ������
	{
		fwrite(&b, sizeof(contact), 1, writefile);
		fread(&b, sizeof(contact), 1, readfile);
	}

	fclose(readfile);
	fclose(writefile);
	printf("��ϵ����Ϣ����ɹ���\n");
	remove("D:\\contact.rec");
	rename("D:\\contacts.rec", "D:\\contact.rec");
	return 0;
}