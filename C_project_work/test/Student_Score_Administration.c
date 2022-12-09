#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h" 
void stuinfor_menu()
{
	//system("cls");
	printf("-----------------------------------------------\n");
	printf("************     学生信息维护      ************\n");
	printf("************    1.添加学生信息     ************\n");
	printf("************    2.删除学生信息     ************\n");
	printf("************    3.修改学生信息     ************\n");
	printf("************    4.查找学生信息     ************\n");
	printf("************    0.退出             ************\n");
	printf("-----------------------------------------------\n");
}
//学生信息维护
void Student_information(System *ps)
{
	assert(ps != NULL);
	int choice = 0;
	do
	{
		stuinfor_menu();
		printf("请选择：>");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case ADD_STU:
			//Add_stu(&ps);
			break;
		case DEL_STU:
			break;
		case MODIFY:
			break;
		case SEARCH:
			break;
		case Exit:
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}

	} while (choice);
	
}

//初始化学生信息结构体（动态分配内存）
 void Init_information(System *ps)
{
	assert(ps!=NULL);
	ps->stu_data = (Stuinfor *)calloc(DEFAULT_SZ, sizeof(Stuinfor));
	if (ps->stu_data == NULL)
	{
		strerror(errno);
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//load_contact(ps);
}

 //判断stu_data是否已满
 void Isfull(System  *ps)
{
	 assert(ps != NULL);
	 if (ps->size == ps->capacity)
	 {
		 struct Stuinfor *p = (Stuinfor *)realloc(ps->stu_data, (ps->capacity + 2)*sizeof(System));//修正动态分配的空间
		 if (p != NULL)
		 {
			 (ps->capacity) = (ps->capacity) + 2;
			 ps->stu_data = p;
			 printf("扩容成功\n");
		 }
		 else
		 {
			 printf("扩容失败\n");
			 return;
		 }
	 }
}

 //添加学生信息
 void Add_stu(System **ps)
 {
	 system("cls");
	 assert(*ps != NULL);
	 Isfull(*ps);
	 printf("请输入学号：>");
	 scanf("%d",&((*ps)->stu_data[(*ps)->size]).ID);
	 printf("请输入姓名：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].name);
	 //gets((*ps)->stu_data[(*ps)->size].name);
	 printf("请输入性别：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].gender);
	 //gets((*ps)->stu_data[(*ps)->size].gender);
	 printf("请输入出生年月：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].birth);
	 printf("请输入住址：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].Addr);
	 //gets((*ps)->stu_data[(*ps)->size].Addr);
	 printf("请输入电话号码：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].Tel);
	 //gets((*ps)->stu_data[(*ps)->size].Tel);
	 printf("请输入邮箱：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].E_mail);
	 //gets((*ps)->stu_data[(*ps)->size].E_mail);
	 (*ps)->size++;
	 printf("添加成功\n");
 }
 //显示学生信息
 void print(const System *ps)
 {
	 assert(ps!=NULL);
	 if (ps->size == 0)
	 {
		 printf("通讯录为空\n");
	 }
	 else
	 {
		 //printf("                       通讯录\n");
		 int i = 0;
		 printf("-------------------------------------------------------\n");
		 printf("   %-10s\t%-5s\t%-12s\t%-20s\t%-20s\t%-15s\t%-20s\n", "学号", "姓名", "性别", "出生年月", "住址","电话号码","邮箱");
		 for (i = 0; i < ps->size; i++)
		 {
			 printf("%d. %-10s\t%-5s\t%-12s\t%-20s\t%-20s\t%-15s\t%-20s\n", i + 1,
				 ps->stu_data[i].ID,
				 ps->stu_data[i].name,
				 ps->stu_data[i].gender,
				 ps->stu_data[i].birth,
				 ps->stu_data[i].Addr,
				 ps->stu_data[i].Tel,
				 ps->stu_data[i].E_mail);
		 }
		 printf("-------------------------------------------------------\n");
	 }
 }