#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include<assert.h>
//#define MAX_ID 20
#define MAX_NAME 20
#define MAX_GENDER 20
#define MAX_BIRTH 20
#define MAX_Addr 40
#define MAX_TELE 15
#define MAX_MAIL 20
#define DEFAULT_SZ 3//默认stu_data初始size为3

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
	PRESENT,
	SAVE

};

enum
{
	Exit,
	ADD_STU,
	DEL_STU,
	MODIFY,
	SEARCH

};
typedef struct Stuinfor
{
	int ID;
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	char birth[MAX_BIRTH];
	char Addr[MAX_Addr];
	char Tel[MAX_TELE];
	char E_mail[MAX_MAIL];

}Stuinfor;

typedef struct System
{
	struct Stuinfor *stu_data;
	int size;
	int capacity;
}System;

//初始化学生信息
void Init_information(System *ps);
//学生信息维护
void Student_infor(System *ps);
//课程信息维护
void Curriculum_information();
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
//显示学生信息
void print();
//保存学生信息
void Save_infor();
//添加学生信息
void Add_stu(System *ps);