#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"


int delete()
{
	int i, n, j = 1;                                           //iΪ�ṹ�����ʱ������jΪ�ṹ��д��ʱ������n�����û���������
	contact a[11];                                             //�ṹ��������1~10�����ļ��е�����
	FILE*readfile;
	FILE*writefile;

	readfile = fopen("D:\\contact.rec", "rb");
	if (!readfile)
	{
		printf("��ϵ���ļ����ܲ���ָ��·���£�\n");
		exit(1);
	}
	writefile = fopen("D:\\contacts.rec", "wb");
	if (!writefile)
	{
		printf("�µ���ϵ���ļ����ܲ���ָ��·���£�\n");
		exit(1);
	}

	printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
	fread(&a[1], sizeof(contact), 1, readfile);
	for (i = 1; (i <= 10) && (!feof(readfile)); i++)
	{
		printf("%2d\t\t%-16s%-48s%-16s%-16s%-24s%-16s%-18s\n\n", i, a[i].name, a[i].units, a[i].tel, a[i].mob, a[i].email, a[i].qq, a[i].kind);

		while (i == 10)                                              //�����һҳ�Ĵ���
		{
			n = 100;
			printf("������Ҫɾ������ϵ�˵����У�1~%d�������� 0 �˳��ù��ܻ����� 11 ����ʾ��һҳ��	", i);
			fflush(stdin);
			scanf("%d", &n);
			if (n > i + 1)
			{
				printf("���������Ϣ�����д��������ԣ�\n");
				continue;
			}

			if (0 < n&&n <10)
			{
				for (; j < n; j++)                                   //д�뵽����Ϊn-1Ϊֹ
				{
					fwrite(&a[j], sizeof(contact), 1, writefile);
				}
				j = n + 1;                                             //ʹ��һ�δ�������n+1��ʼд��
				printf("\n��ɾ������ϵ��\n\n");
				continue;
			}

			if (n == 11 || n == 10)
			{
				for (; j < n; j++)
					fwrite(&a[j], sizeof(contact), 1, writefile);
				system("cls");
				printf("index\t\tname\t\tunits\t\t\t\t\t\ttel\t\tmob\t\temail\t\t\tqq\t\tkind\n\n");
				i = 0;                                               //Ϊi��ֵ��ʹ��ʾ���ܹ�������1~10����
				j = 1;                                               //ʹд���ļ��ӽṹ��ĵ�һ��д��
				break;
			}

			if (n == 0)                                              //�˳�while��ѭ��
			{
				break;
			}
		}

		if (n == 0)
		{

			for (n = 11; j < n; j++)                                 //����һҳʣ������д��
				fwrite(&a[j], sizeof(contact), 1, writefile);

			fread(&a[0], sizeof(contact), 1, readfile);              //��Ϊ�ļ���ʣ������д��
			while (!feof(readfile))
			{
				fwrite(&a[0], sizeof(contact), 1, writefile);
				fread(&a[0], sizeof(contact), 1, readfile);
			}
			break;
		}

		fread(&a[i + 1], sizeof(contact), 1, readfile);

		while (feof(readfile))                                       //���һҳ�Ĵ���
		{
			fflush(stdin);
			printf("\n������Ҫɾ������ϵ�˵����У�1~%d�������� 0 �˳��ù��ܻ����� 11 ����ʾ��һҳ��	", i);
			scanf("%d", &n);
			if (n > i)
			{
				printf("���������Ϣ�����д��������ԣ�\n");
				continue;
			}

			if (0 < n&&n < i)
			{
				for (; j < n; j++)
				{
					fwrite(&a[j], sizeof(contact), 1, writefile);
				}
				printf("\n��ɾ������ϵ��\n");
				j = n + 1;
				continue;
			}

			if (n == i || n == 0)
			{
				if (n == 0)                                          //ʹ��n=0��n=i����ʹ��
					n = i + 1;

				for (; j < n; j++)
					fwrite(&a[j], sizeof(contact), 1, writefile);
				break;
			}
		}
	}

	fclose(readfile);
	fclose(writefile);
	remove("D:\\contact.rec");                                       //ɾ���ļ���
	rename("D:\\contacts.rec", "D:\\contact.rec");                   //�޸��ļ�������
	return 0;
}