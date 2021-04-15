#ifndef CONTACTS_H
#define CONTACTS_H

typedef struct			//储存联系人信息的结构体
{
	char name[20];		//姓名
	char units[50];		//单位
	char tel[15];		//固定电话
	char mob[15];		//移动电话
	char email[30];		//电子邮箱
	char qq[20];		//QQ号
	char kind[15];		//联系人类别
}contact;

int add();
int display();
int search();
int alter();
int delete();

#endif