#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h"
void menu()
{
	system("cls");
	printf("************   ѧ����Ϣ����ϵͳ    *************\n");
	printf("************    1.ѧ����Ϣά��     ************\n");
	printf("************    2.�γ���Ϣά��     ************\n"); 
	printf("************    3.�ɼ���Ϣά��     ************\n");
	printf("************    4.ѧ���ɼ�ͳ��     ************\n");
	printf("************    5.ѧ��ѧ��ͳ��     ************\n");
	printf("************    6.�γ̳ɼ�����     ************\n");
	printf("************    7.ѧ��ƽ��������   ************\n");
	printf("************    8.��ʾѧ����Ϣ     ************\n");
	printf("************    0.�˳�����ϵͳ     ************\n");
}        
int main()
{
	struct Stuinfor s[MAX];
	Init_infor(s);
	int choice=0;
    do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &choice);
		switch (choice)
		{  
		case 1:
			//Student_information();
			break;
		case 2:
			//Curriculum_information();
			break;
		case 3:
			//Score_information();
			break;
		case 4:
			//Score_statistics();
			break;
		case 5:
			//Credit_statistics();
			break;
		case 6:
			//Score_sort();
			break;
		case 7:
			//Average_sort();
			break;
		case 8:
			//print();
			break;
		case 0:
			printf("�˳�ϵͳ\n");
			break;
		default:
			printf("����������������룡");
			break;
		}
	} while (choice);
	return 0;
}