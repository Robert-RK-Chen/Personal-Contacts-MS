#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contacts.h"

int search()
{
	char find[50];					//����Ҫ���ҵ���Ϣ
	int  i;

	FILE *readfile;
	contact a;

L2:	readfile = fopen("D:\\contact.rec", "rb");				//�����Ʒ�ʽ���ļ�
	if (!readfile)
	{
		printf("��ϵ���ļ����ܲ���ָ��·���£�\n\n");
		return 0;
	}

	printf("������ ���� �Բ��ҵ���Ϣ��	");				//����
	fflush(stdin);
	scanf("%s", &find);

	while (1)
	{
		fread(&a, sizeof(contact), 1, readfile);
		if (strcmp(a.name, find) == 0)					//���ҵ����ȫ����Ϣ
		{
			printf("\n�������ҵ���Ϣ���£�\n");
			printf("*******************\n");
			printf("��    ����%s\n", &a.name);
			printf("��    λ��%s\n", &a.units);
			printf("�̶��绰��%s\n", &a.tel);
			printf("�ƶ��绰��%s\n", &a.mob);
			printf("�������䣺%s\n", &a.email);
			printf("Q    Q�ţ�%s\n", &a.qq);
			printf("��ϵ�����%s\n", a.kind);
			printf("*******************\n");
			break;
		}

		else if (feof(readfile))
		{
			printf("δ���ҵ�����Ҫ����Ϣ��\n\n");			//δ�ҵ�����
			break;
		}
	}

	while (1)
	{
		i = 0;
		printf("������ 1 �Լ������ң������������˳��ù��ܣ�	");
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