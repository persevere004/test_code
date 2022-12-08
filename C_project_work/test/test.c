#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h"
void main_menu()
{
	system("cls");
	printf("-----------------------------------------------\n");
	printf("************   学生信息管理系统    ************\n");
	printf("************    1.学生信息维护     ************\n");
	printf("************    2.课程信息维护     ************\n"); 
	printf("************    3.成绩信息维护     ************\n");
	printf("************    4.学生成绩统计     ************\n");
	printf("************    5.学生学分统计     ************\n");
	printf("************    6.课程成绩排名     ************\n");
	printf("************    7.学生平均分排名   ************\n");
	printf("************    8.显示学生信息     ************\n");
	printf("************    9.保存学生信息     ************\n");
	printf("************    0.退出管理系统     ************\n");
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
		printf("请选择:> ");
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
			printf("保存成功\n");
			break;
		case EXIT:
			//Save_infor();
			printf("退出系统\n");
			break;
		default :
			printf("输入错误，请重新输入！");
			break;
		}
	} while (choice);
	return 0;
}