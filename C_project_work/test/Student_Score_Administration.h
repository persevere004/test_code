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
//��ʼ��ѧ����Ϣ
void Init_Stu_data(System1 *ps);
//ѧ����Ϣά��
void Student_information(System1 *ps);
//�γ���Ϣά��
void Course_information();
//�ɼ���Ϣά��
void Score_information();
//ѧ���ɼ�ͳ��
void Score_statistics();
//ѧ��ѧ��ͳ��
void Credit_statistics();
//�γ̳ɼ�����
void Score_sort();
//ѧ��ƽ��������
void Average_sort();
//����ѧ����Ϣ
void Save_infor();
//���ѧ����Ϣ
void Add_stu(System1 **ps);
//ɾ��ѧ����Ϣ
void Del_stu(System1 **ps);
//�޸�ѧ����Ϣ
void Modify_stu(System1 **ps);
//����ѧ����Ϣ
void Search_stu(const System1 **ps);
//��ʾѧ����Ϣ
void Print_stu(const System1 **ps);
//��ʼ���γ���Ϣ
void Init_Course_data(System2 *pc);
//��ӿγ���Ϣ
void Add_course(System2 **pc);
//ɾ���γ���Ϣ
void Del_course(System2 **pc);
//�޸Ŀγ���Ϣ
void Modify_course(System2 **pc);
//���ҿγ���Ϣ
void Search_course(const System2 **pc);
//��ʾ�γ���Ϣ
void Print_course(const System2 **pc);

