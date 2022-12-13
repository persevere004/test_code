#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h" 
//学生信息维护系统功能菜单
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
		    Add_stu(&ps);//添加学生信息
			break;
		case DEL_STU:
			Del_stu(&ps);
			break;
		case MODIFY:
			Modify_stu(&ps);
			break;
		case SEARCH:
			Search_stu(&ps);//查找学生信息
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
		 ps->stu_data = (Stuinfor *)realloc(ps->stu_data, (ps->capacity + 2)*sizeof(Stuinfor));//修正动态分配的空间
		 if (ps != NULL)
		 {
			 (ps->capacity) = (ps->capacity) + 2;
			// ps->stu_data = p;
			 printf("扩容成功\n");
		 }
		 else
		 {
			 printf("扩容失败\n");
			 return;
		 }
	 }
}
 //按姓名查找学生
 static int Find_by_name(const System *ps, char *name)
 {
	 int i = 0;
	 for (i = 0; i < ps->size; i++)
	 {
		 if (strcmp(name, ps->stu_data[i].name) == 0)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 //按学号查找学生
 static int Find_by_ID(const System *ps, int ID)
 {
	 int i = 0;
	 for (i = 0; i < ps->size; i++)
	 {
		 if (ID == (ps->stu_data[i].ID))
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 //添加学生信息
 void Add_stu(System **ps)
 {
	 system("cls");
	 assert(*ps != NULL);
	 Isfull(*ps);
	 printf("请输入学号：>");
	 scanf("%d", &((*ps)->stu_data[(*ps)->size]).ID);
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
 //删除学生信息
 void Del_stu(System** ps)
 {
	 char name[MAX_NAME];
	 int n = 0;
	 int ID = 0;
	 int ret = 0;
	 if ((*ps)->size == 0)
	 {
		 printf("暂无学生信息\n");
	 }
	 else
	 {
		 printf("按学号删除------1\n");
		 printf("按名字删除------2\n");
		 do
		 {
			 printf("请选择:>");
			 scanf("%d", &n);
			 if (n == 1)
			 {
				 printf("请输入要删除学生的学号:>");
				 scanf("%d", &ID);
				 ret = Find_by_ID((*ps), ID);
				 break;
			 }
			 else if (n == 2)
			 {
				 printf("请输入要删除学生的姓名:>");
				 scanf("%s", name);
				 ret = Find_by_name((*ps), name);
				 break;
			 }
			 else
			 {
				 printf("输入错误，请重新输入！\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("查无此人！\n");
		 }
		 else
		 {
			 memmove(&((*ps)->stu_data[ret]), &((*ps)->stu_data[ret + 1]), ((*ps)->size)*sizeof((*ps)->stu_data[0]));
			 (*ps)->size--;
			 printf("删除成功！\n");
		 }
	 }
 }
 //修改学生信息菜单
 void Modify_menu_stu()
 {
	 printf("修改学号----------1\n");
	 printf("修改姓名----------2\n");
	 printf("修改性别----------3\n");
	 printf("修改出生日期------4\n");
	 printf("修改地址----------5\n");
	 printf("修改电话----------6\n");
	 printf("修改邮箱----------7\n");
 }
 //修改学生信息
 void Modify_stu(System **ps)
 {
	 char name[MAX_NAME];
	 int a = 0;
	 int ID = 0;
	 int ret = 0;
	 int b = 0;
	 if ((*ps)->size == 0)
	 {
		 printf("暂无学生信息\n");
	 }
	 else
	 {
		 printf("按学号查找------1\n");
		 printf("按名字查找------2\n");
		 do
		 {
			 printf("请选择:>");
			 scanf("%d", &a);
			 if (a == 1)
			 {
				 printf("请输入要修改学生的学号:>");
				 scanf("%d", &ID);
				 ret = Find_by_ID((*ps), ID);
				 break;
			 }
			 else if (a == 2)
			 {
				 printf("请输入要修改学生的姓名:>");
				 scanf("%s", name);
				 ret = Find_by_name((*ps), name);
				 break;
			 }
			 else
			 {
				 printf("输入错误，请重新输入！\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("查无此人！\n");
		 }
		 else
		 {
			 Mpdify_menu_stu();
			 printf("请选择:>");
			 scanf("%d", &b);
			 switch (b)
			 {
			 case Id:
				 printf("请输入学号:>");
				 scanf();
				 break;
			 case NAME:
				 break;
			 case GENDER:
				 break;
			 case BIRTH:
				 break;
			 case ADDR:
				 break;
			 case TEL:
				 break;
			 case E_MAIL:
				 break;
			 case EXIT:
				 break;
			 default:
				 break;
			 }
		 }
	 }
 }
//查找学生信息
 void Search_stu(const System **ps)
 {
	 char name[MAX_NAME];
	 int n = 0;
	 int ID=0;
	 int ret = 0;
	 if ((*ps)->size == 0)
	 {
		 printf("暂无学生信息\n");
	 }
	 else
	 {
		 printf("按学号查找------1\n");
		 printf("按名字查找------2\n");
		 do
		 {
			 printf("请选择:>");
			 scanf("%d", &n);
			 if (n == 1)
			 {
				 printf("请输入要查找学生的学号:>");
				 scanf("%d", &ID);
				 ret=Find_by_ID((*ps), ID);
				 break;
			 }
			 else if (n == 2)
			 {
				 printf("请输入要查找学生的姓名:>");
				 scanf("%s", name);
				 ret=Find_by_name((*ps), name);
				 break;
			 }
			 else
			 {
				 printf("输入错误，请重新输入！\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("查无此人!\n");
		 }
		 else
		 {
			 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			 printf(" %-12s\t%-10s\t%-12s\t%-10s\t%-25s\t%-20s\t%-30s\n", "学号", "姓名", "性别", "出生年月", "住址", "电话号码", "邮箱");
			 printf(" %-12d\t%-10s\t%-12s\t%-10s\t%-25s\t%-20s\t%-30s\n",
				 (*ps)->stu_data[ret].ID,
				 (*ps)->stu_data[ret].name,
				 (*ps)->stu_data[ret].gender,
				 (*ps)->stu_data[ret].birth,
				 (*ps)->stu_data[ret].Addr,
				 (*ps)->stu_data[ret].Tel,
				 (*ps)->stu_data[ret].E_mail);
			 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		 }
	 }
}
 //显示学生信息
 void print(const System *ps)
 {
	 assert(ps!=NULL);
	 if (ps->size == 0)
	 {
		 printf("暂无学生信息！\n");
	 }
	 else
	 {
		
		 int i = 0;
		 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		 printf("   %-12s\t%-10s\t%-5s\t%-10s\t%-25s\t%-20s\t%-25s\n", "学号", "姓名", "性别", "出生年月", "住址","电话号码","邮箱");
		 for (i = 0; i < ps->size; i++)
		 {
			 printf("%d. %-12d\t%-10s\t%-5s\t%-10s\t%-25s\t%-20s\t%-25s\n", i + 1,
				 ps->stu_data[i].ID,
				 ps->stu_data[i].name,
				 ps->stu_data[i].gender,
				 ps->stu_data[i].birth,
				 ps->stu_data[i].Addr,
				 ps->stu_data[i].Tel,
				 ps->stu_data[i].E_mail);
		 }
		 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	 }
 }