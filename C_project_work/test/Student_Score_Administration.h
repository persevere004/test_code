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
#define DEFAULT_SZ 3//Ĭ��stu_data��ʼsizeΪ3

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

//��ʼ��ѧ����Ϣ
void Init_information(System *ps);
//ѧ����Ϣά��
void Student_infor(System *ps);
//�γ���Ϣά��
void Curriculum_information();
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
//��ʾѧ����Ϣ
void print();
//����ѧ����Ϣ
void Save_infor();
//���ѧ����Ϣ
void Add_stu(System *ps);