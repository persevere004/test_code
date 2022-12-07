#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h"
void menu()
{
	system("cls");
	printf("************   学生信息管理系统    *************\n");
	printf("************    1.学生信息维护     ************\n");
	printf("************    2.课程信息维护     ************\n"); 
	printf("************    3.成绩信息维护     ************\n");
	printf("************    4.学生成绩统计     ************\n");
	printf("************    5.学生学分统计     ************\n");
	printf("************    6.课程成绩排名     ************\n");
	printf("************    7.学生平均分排名   ************\n");
	printf("************    8.显示学生信息     ************\n");
	printf("************    0.退出管理系统     ************\n");
}        
int main()
{
	struct Stuinfor s[MAX];
	Init_infor(s);
	int choice=0;
    do
	{
		menu();
		printf("请选择:> ");
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
			printf("退出系统\n");
			break;
		default:
			printf("输入错误，请重新输入！");
			break;
		}
	} while (choice);
	return 0;
}