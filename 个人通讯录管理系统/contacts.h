#ifndef CONTACTS_H
#define CONTACTS_H

typedef struct			//������ϵ����Ϣ�Ľṹ��
{
	char name[20];		//����
	char units[50];		//��λ
	char tel[15];		//�̶��绰
	char mob[15];		//�ƶ��绰
	char email[30];		//��������
	char qq[20];		//QQ��
	char kind[15];		//��ϵ�����
}contact;

int add();
int display();
int search();
int alter();
int delete();

#endif