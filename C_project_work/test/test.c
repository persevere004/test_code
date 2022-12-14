#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h"
void main_menu()
{
	//system("cls");
	printf("--------------------------------------------------------------\n");
	printf("************            学生信息管理系统          ************\n");
	printf("************    1.学生信息维护   2.课程信息维护   ************\n"); 
	printf("************    3.成绩信息维护   4.学生成绩统计   ************\n");
	printf("************    5.学生学分统计   6.课程成绩排名   ************\n");
	printf("************    7.学生平均分排名 8.保存学生信息   ************\n");
	printf("************            0.退出管理系统            ************\n");
	printf("--------------------------------------------------------------\n");
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
		printf("请选择:> ");
		scanf("%d", &choice);
		//getchar();
		switch (choice)
		{
        //学生信息维护  
		case STU_INFOR:
			Student_information(&Stu);
			break;
		//课程信息维护
		case CURRICULU_INFOR:
			Course_information(&Course);
			break;
		//成绩信息维护
		case SCORE_INFOR:
			//Score_information();
			break;
		//学生成绩统计
		case SCORE_STATISTICS:
			//Score_statistics();
			break;
		//学生学分统计
		case CREDIT_STATISTICS:
			//Credit_statistics();
			break;
		//课程成绩排名
		case SORT_BY_SCORE:
			//Score_sort();
			break;
		//学生平均分排名
		case SORT_BY_AVERAGE:
			//Average_sort();
			break;
        //保存数据  
		case SAVE:
			//Save_infor();
			printf("保存成功\n");
			break;
	    //退出并释放内存同时保存数据
		case EXIT:
			free(Stu.stu_data);
			free(Course.course_data);
			Stu.stu_data = NULL;
			Course.course_data = NULL;
			//Save_infor();
			printf("已退出\n");
			break;
		default :
			printf("输入错误，请重新输入\n！");
			break;
		}
	} while (choice);
	return 0;
}