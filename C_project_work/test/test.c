#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h"
void main_menu()
{
	system("cls");
	printf("-----------------------------------------------\n");
	printf("************   ѧ����Ϣ����ϵͳ    ************\n");
	printf("************    1.ѧ����Ϣά��     ************\n");
	printf("************    2.�γ���Ϣά��     ************\n"); 
	printf("************    3.�ɼ���Ϣά��     ************\n");
	printf("************    4.ѧ���ɼ�ͳ��     ************\n");
	printf("************    5.ѧ��ѧ��ͳ��     ************\n");
	printf("************    6.�γ̳ɼ�����     ************\n");
	printf("************    7.ѧ��ƽ��������   ************\n");
	printf("************    8.��ʾѧ����Ϣ     ************\n");
	printf("************    9.����ѧ����Ϣ     ************\n");
	printf("************    0.�˳�����ϵͳ     ************\n");
	printf("-----------------------------------------------\n");
}        

int main()
{
     System Stu;
	Init_information(&Stu);
	int choice=0;
    do
	{
		main_menu();
		printf("��ѡ��:> ");
		scanf("%d", &choice);
		//getchar();
		switch (choice)
		{
		case STU_INFOR:
			Student_information(&Stu);
			break;
		case CURRICULU_INFOR:
			//Curriculum_information();
			break;
		case SCORE_INFOR:
			//Score_information();
			break;
		case SCORE_STATISTICS:
			//Score_statistics();
			break;
		case CREDIT_STATISTICS:
			//Credit_statistics();
			break;
		case SORT_BY_SCORE:
			//Score_sort();
			break;
		case SORT_BY_AVERAGE:
			//Average_sort();
			break;
		case PRESENT:
			print();
			break;
		case SAVE:
			//Save_infor();
			printf("����ɹ�\n");
			break;
		case EXIT:
			//Save_infor();
			printf("�˳�ϵͳ\n");
			break;
		default :
			printf("����������������룡");
			break;
		}
	} while (choice);
	return 0;
}