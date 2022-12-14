#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include<assert.h>
#define MAX_NAME 20
#define MAX_GENDER 20
#define MAX_BIRTH 20
#define MAX_Addr 40
#define MAX_TELE 15
#define MAX_MAIL 20
#define DEFAULT_SZ 5

enum
{
	EXIT,
	STU_INFOR,
	CURRICULU_INFOR,
	SCORE_INFOR,
	SCORE_STATISTICS,
	CREDIT_STATISTICS,
	SORT_BY_SCORE,
	SORT_BY_AVERAGE,
	SAVE

};

enum
{
	ADD=1,
	DEL=2,
	MODIFY=3,
	SEARCH=4,
	PRENSENT=5

};
enum
{
	Id=1,
	NAME=2,
	GENDER=3,
	BIRTH=4,
	ADDR=5,
	TEL=6,
	E_MAIL=7
};
enum
{
	COURSENO = 1,
	COURSENAME = 2,
	COURSECREDIT=3
};
typedef struct Stu_infor
{
	int ID;
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	char birth[MAX_BIRTH];
	char Addr[MAX_Addr];
	char Tel[MAX_TELE];
	char E_mail[MAX_MAIL];

}Stu_infor;

typedef struct System1
{
	struct Stu_infor *stu_data;
	int stu_size;
	int stu_capacity;
}System1;

typedef struct Course_infor
{
	char course_name[MAX_NAME];
	int course_NO;
	int course_credit;
}Course_infor;

typedef struct System2
{
	struct Course_infor *course_data;
	int course_size;
	int course_capacity;
}System2;
//初始化学生信息
void Init_Stu_data(System1 *ps);
//学生信息维护
void Student_information(System1 *ps);
//课程信息维护
void Course_information();
//成绩信息维护
void Score_information();
//学生成绩统计
void Score_statistics();
//学生学分统计
void Credit_statistics();
//课程成绩排名
void Score_sort();
//学生平均分排名
void Average_sort();
//保存学生信息
void Save_infor();
//添加学生信息
void Add_stu(System1 **ps);
//删除学生信息
void Del_stu(System1 **ps);
//修改学生信息
void Modify_stu(System1 **ps);
//查找学生信息
void Search_stu(const System1 **ps);
//显示学生信息
void Print_stu(const System1 **ps);
//初始化课程信息
void Init_Course_data(System2 *pc);
//添加课程信息
void Add_course(System2 **pc);
//删除课程信息
void Del_course(System2 **pc);
//修改课程信息
void Modify_course(System2 **pc);
//查找课程信息
void Search_course(const System2 **pc);
//显示课程信息
void Print_course(const System2 **pc);

