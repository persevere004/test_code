#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h"
void main_menu()
{
	//system("cls");
	printf("-----------------------------------------------\n");
	printf("************   ѧ����Ϣ����ϵͳ    ************\n");
	printf("************    1.ѧ����Ϣά��     ************\n");
	printf("************    2.�γ���Ϣά��     ************\n"); 
	printf("************    3.�ɼ���Ϣά��     ************\n");
	printf("************    4.ѧ���ɼ�ͳ��     ************\n");
	printf("************    5.ѧ��ѧ��ͳ��     ************\n");
	printf("************    6.�γ̳ɼ�����     ************\n");
	printf("************    7.ѧ��ƽ��������   ************\n");
	printf("************    8.����ѧ����Ϣ     ************\n");
	printf("************    0.�˳�����ϵͳ     ************\n");
	printf("-----------------------------------------------\n");
}        

int main()
{
     System1 Stu;
	 System2 Course;
	 Init_Course_data(&Course);
	Init_Stu_data(&Stu);
	int choice=0;
    do
	{
		main_menu();
		printf("��ѡ��:> ");
		scanf("%d", &choice);
		//getchar();
		switch (choice)
		{
        //ѧ����Ϣά��  
		case STU_INFOR:
			Student_information(&Stu);
			break;
		//�γ���Ϣά��
		case CURRICULU_INFOR:
			Course_information(&Course);
			break;
		//�ɼ���Ϣά��
		case SCORE_INFOR:
			//Score_information();
			break;
		//ѧ���ɼ�ͳ��
		case SCORE_STATISTICS:
			//Score_statistics();
			break;
		//ѧ��ѧ��ͳ��
		case CREDIT_STATISTICS:
			//Credit_statistics();
			break;
		//�γ̳ɼ�����
		case SORT_BY_SCORE:
			//Score_sort();
			break;
		//ѧ��ƽ��������
		case SORT_BY_AVERAGE:
			//Average_sort();
			break;
        //��������  
		case SAVE:
			//Save_infor();
			printf("����ɹ�\n");
			break;
	    //�˳����ͷ��ڴ�ͬʱ��������
		case EXIT:
			free(Stu.stu_data);
			free(Course.course_data);
			Stu.stu_data = NULL;
			Course.course_data = NULL;
			//Save_infor();
			printf("���˳�\n");
			break;
		default :
			printf("�����������������\n��");
			break;
		}
	} while (choice);
	return 0;
}