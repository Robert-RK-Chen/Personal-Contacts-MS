#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

int main()
{
	int button;
L1:	system("cls");
L2:	button = 0;
	printf("\n***** 个人通讯录管理系统菜单 ******\n");				//菜单功能页面
	printf("*                                 *\n");
	printf("*     输入 1 ：显示所有联系人     *\n");
	printf("*                                 *\n");
	printf("*     输入 2 ：添加新的联系人     *\n");
	printf("*                                 *\n");
	printf("*     输入 3 ：查 找 联 系 人     *\n");
	printf("*                                 *\n");
	printf("*     输入 4 ：修改联系人信息     *\n");
	printf("*                                 *\n");
	printf("*     输入 5 ：删 除 联 系 人     *\n");
	printf("*                                 *\n");
	printf("*     输入 6 ：退 出 该 程 序     *\n");
	printf("*                                 *\n");
	printf("***********************************\n\n");
	printf("请输入数字以执行您想访问的功能：");
	fflush(stdin);
	scanf("%d", &button);

	switch (button)						//每一个数字对应一个功能
	{
	case 1:
		system("cls");
		printf("********************************\n");
		printf("\n你选择了功能 1 :显示所有联系人\n\n");
		printf("********************************\n\n");
		display();
		system("Pause");
		goto L1;

	case 2:
		system("cls");
		printf("********************************\n");
		printf("\n你选择了 功能2 : 添加新的联系人\n\n");
		printf("********************************\n\n");
		add();
		system("Pause");
		goto L1;

	case 3:
		system("cls");
		printf("********************************\n");
		printf("\n你选择了功能 3 :查 找 联 系 人\n\n");
		printf("********************************\n\n");
		search();
		system("Pause");
		goto L1;

	case 4:
		system("cls");
		printf("********************************\n");
		printf("\n你选择了功能 4 :修改联系人信息\n\n");
		printf("********************************\n\n");
		alter();
		system("Pause");
		goto L1;

	case 5:
		system("cls");
		printf("********************************\n");
		printf("\n你选择了功能 5 :删 除 联 系 人\n\n");
		printf("********************************\n\n");
		delete();
		system("Pause");
		goto L1;

	case 6:
		system("cls");
		break;

	default:
		system("cls");
		printf("\n暂未开发对应的功能，请尝试数字 1 ~ 6 的功能哦！\n");
		printf("----------------------------------------------\n");
		goto L2;
	}
	return 0;
}