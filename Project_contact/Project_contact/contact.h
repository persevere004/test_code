#include <stdio.h>
#include <string.h>
#include<windows.h>
#define NAME 20
#define TELE 20
#define ADDRESS 50
#define DEFAULT_SZ 3//Ĭ��ͨѶ¼��ʼ����Ϊ3
//#define MAX 1000
#define GENDER 5
enum
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,
	PRINT,
	SORT ,
	SAVE
};
enum
{
	Exit,
	Name,
	Age,
	Tele,
	Addr,
	Gender

};
struct peoinfor
{
	char name[NAME];
	char tele[TELE];
	char gender[GENDER];
	char addr[ADDRESS];
	int age;
};
struct contact
{
	struct peoinfor *data;
	int size;//��ǰͨѶ¼������
	int capacity;//��ǰͨѶ¼������
};
//��ʼ��ͨѶ¼
void Initcontact(struct contact *ps);
//�����ϵ��
void Add(struct contact *ps);
//ɾ����ϵ��
void del(struct contact *ps);
//��ӡ��ϵ��
void print(const struct contact *ps);
//������ϵ��
void search(const struct contact *ps);
//�޸���ϵ����Ϣ
void modify(struct contact *ps);
//����
void sort(struct contact *ps);
//�ͷ��ڴ�
void freedata(struct contact*ps);
//��ͨѶ¼���浽�ļ���
void save_contact(struct contact *ps);

