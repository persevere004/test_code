#include <stdio.h>
#include <string.h>
#include<windows.h>
#define NAME 20
#define TELE 20
#define ADDRESS 50
#define DEFAULT_SZ 3//默认通讯录初始容量为3
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
	int size;//当前通讯录的人数
	int capacity;//当前通讯录的容量
};
//初始化通讯录
void Initcontact(struct contact *ps);
//添加联系人
void Add(struct contact *ps);
//删除联系人
void del(struct contact *ps);
//打印联系人
void print(const struct contact *ps);
//查找联系人
void search(const struct contact *ps);
//修改联系人信息
void modify(struct contact *ps);
//排序
void sort(struct contact *ps);
//释放内存
void freedata(struct contact*ps);
//把通讯录保存到文件中
void save_contact(struct contact *ps);

