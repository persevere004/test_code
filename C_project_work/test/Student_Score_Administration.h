#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ID 10
#define MAX_NAME 10
#define MAX_GENDER 2
#define MAX_BIRTH 8
#define MAX 1000
struct Stuinfor
{
	char ID[MAX_ID];
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	char birth[MAX_BIRTH];
};
struct system
{
	int size;
	struct Stuinfor s[MAX];
}*s;
void Init_infor(struct system *ps);
void Student_information();
void Curriculum_information();
void Score_information();
void Score_statistics();
void Credit_statistics();
void Score_sort();
void Average_sort();
void print();