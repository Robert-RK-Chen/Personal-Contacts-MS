#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

int main()
{
	int button;
L1:	system("cls");
L2:	button = 0;
	printf("\n***** ����ͨѶ¼����ϵͳ�˵� ******\n");				//�˵�����ҳ��
	printf("*                                 *\n");
	printf("*     ���� 1 ����ʾ������ϵ��     *\n");
	printf("*                                 *\n");
	printf("*     ���� 2 ������µ���ϵ��     *\n");
	printf("*                                 *\n");
	printf("*     ���� 3 ���� �� �� ϵ ��     *\n");
	printf("*                                 *\n");
	printf("*     ���� 4 ���޸���ϵ����Ϣ     *\n");
	printf("*                                 *\n");
	printf("*     ���� 5 ��ɾ �� �� ϵ ��     *\n");
	printf("*                                 *\n");
	printf("*     ���� 6 ���� �� �� �� ��     *\n");
	printf("*                                 *\n");
	printf("***********************************\n\n");
	printf("������������ִ��������ʵĹ��ܣ�");
	fflush(stdin);
	scanf("%d", &button);

	switch (button)						//ÿһ�����ֶ�Ӧһ������
	{
	case 1:
		system("cls");
		printf("********************************\n");
		printf("\n��ѡ���˹��� 1 :��ʾ������ϵ��\n\n");
		printf("********************************\n\n");
		display();
		system("Pause");
		goto L1;

	case 2:
		system("cls");
		printf("********************************\n");
		printf("\n��ѡ���� ����2 : ����µ���ϵ��\n\n");
		printf("********************************\n\n");
		add();
		system("Pause");
		goto L1;

	case 3:
		system("cls");
		printf("********************************\n");
		printf("\n��ѡ���˹��� 3 :�� �� �� ϵ ��\n\n");
		printf("********************************\n\n");
		search();
		system("Pause");
		goto L1;

	case 4:
		system("cls");
		printf("********************************\n");
		printf("\n��ѡ���˹��� 4 :�޸���ϵ����Ϣ\n\n");
		printf("********************************\n\n");
		alter();
		system("Pause");
		goto L1;

	case 5:
		system("cls");
		printf("********************************\n");
		printf("\n��ѡ���˹��� 5 :ɾ �� �� ϵ ��\n\n");
		printf("********************************\n\n");
		delete();
		system("Pause");
		goto L1;

	case 6:
		system("cls");
		break;

	default:
		system("cls");
		printf("\n��δ������Ӧ�Ĺ��ܣ��볢������ 1 ~ 6 �Ĺ���Ŷ��\n");
		printf("----------------------------------------------\n");
		goto L2;
	}
	return 0;
}