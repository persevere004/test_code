#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h" 
//学生信息维护系统功能菜单
void Stu_infor_menu()
{
	//system("cls");
	printf("-----------------------------------------------\n");
	printf("************     学生信息维护      ************\n");
	printf("************    1.添加学生信息     ************\n");
	printf("************    2.删除学生信息     ************\n");
	printf("************    3.修改学生信息     ************\n");
	printf("************    4.查找学生信息     ************\n");
	printf("************    5.学生信息总览     ************\n");
	printf("************    0.退出             ************\n");
	printf("-----------------------------------------------\n");
}
//学生信息维护
void Student_information(System1 *ps)
{
	assert(ps != NULL);
	int choice = 0;
	do
	{
		Stu_infor_menu();
		printf("请选择：>");
		scanf("%d", &choice);
		//getchar();
		switch (choice)
		{
		case ADD:
		    Add_stu(&ps);//添加学生信息
			break;
		case DEL:
			Del_stu(&ps);//删除学生信息
			break;
		case MODIFY:
			Modify_stu(&ps);//修改学生信息
			break;
		case SEARCH:
			Search_stu(&ps);//查找学生信息
			break;
		case PRENSENT:
			Print_stu(&ps);//查找学生信息
			break;
		case EXIT:
			printf("退出学生信息维护\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}

	} while (choice);
	
}

//初始化学生信息结构体（动态分配内存）
 void Init_Stu_data(System1 *ps)
{
	assert(ps!=NULL);
	ps->stu_data = (Stu_infor *)calloc(DEFAULT_SZ, sizeof(Stu_infor));
	if (ps->stu_data == NULL)
	{
		strerror(errno);
		return;
	}
	ps->stu_size = 0;
	ps->stu_capacity = DEFAULT_SZ;
	//load_contact(ps);
}

 //判断stu_data是否已满并修正动态分配的空间
 void Isfull_stu(System1  *ps)
{
	 assert(ps != NULL);
	 if (ps->stu_size == ps->stu_capacity)
	 {
		 //stu_data已满则加10个容量
		 ps->stu_data = (Stu_infor *)realloc(ps->stu_data, (ps->stu_capacity + 10)*sizeof(Stu_infor));
		 if (ps != NULL)
		 {
			 (ps->stu_capacity) = (ps->stu_capacity) + 10;
			 printf("扩容成功\n");
		 }
		 else
		 {
			 printf("扩容失败\n");
			 printf("%s", strerror(errno));
			 return;
		 }
	 }
}
 //按姓名查找学生
 static int Find_by_name(const System1 *ps, char *name)
 {
	 assert(ps != NULL);
	 assert(name != NULL);
	 int i = 0;
	 for (i = 0; i < ps->stu_size; i++)
	 {
		 if (strcmp(name, ps->stu_data[i].name) == 0)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 //按学号查找学生
 static int Find_by_ID(const System1 *ps, int ID)
 {
	 assert(ps!=NULL);
	 int i = 0;
	 for (i = 0; i < ps->stu_size; i++)
	 {
		 if (ID == (ps->stu_data[i].ID))
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 //添加学生信息
 void Add_stu(System1 **ps)
 {
	 system("cls");
	 assert(*ps != NULL);
	 Isfull_stu(*ps);
	 printf("请输入学号：>");
	 scanf("%d", &((*ps)->stu_data[(*ps)->stu_size]).ID);
	 printf("请输入姓名：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->stu_size].name);
	 //gets((*ps)->stu_data[(*ps)->size].name);
	 printf("请输入性别：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->stu_size].gender);
	 //gets((*ps)->stu_data[(*ps)->size].gender);
	 printf("请输入出生年月：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->stu_size].birth);
	 printf("请输入住址：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->stu_size].Addr);
	 //gets((*ps)->stu_data[(*ps)->size].Addr);
	 printf("请输入电话号码：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->stu_size].Tel);
	 //gets((*ps)->stu_data[(*ps)->size].Tel);
	 printf("请输入邮箱：>");
	 scanf("%s", (*ps)->stu_data[(*ps)->stu_size].E_mail);
	 //gets((*ps)->stu_data[(*ps)->size].E_mail);
	 (*ps)->stu_size++;
	 printf("添加成功\n");
 }
 //删除学生信息
 void Del_stu(System1 **ps)
 {
	 assert((*ps) != NULL);
	 char name[MAX_NAME];
	 int n = 0;
	 int ID = 0;
	 int ret = 0;
	 if ((*ps)->stu_size == 0)
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
			 memmove(&((*ps)->stu_data[ret]), &((*ps)->stu_data[ret + 1]), ((*ps)->stu_size)*sizeof((*ps)->stu_data[0]));
			 (*ps)->stu_size--;
			 printf("删除成功！\n");
		 }
	 }
 }
 //修改学生信息菜单
 void Modify_menu_stu()
 {
	 system("cls");
	 printf("修改学号----------1\n");
	 printf("修改姓名----------2\n");
	 printf("修改性别----------3\n");
	 printf("修改出生日期------4\n");
	 printf("修改地址----------5\n");
	 printf("修改电话----------6\n");
	 printf("修改邮箱----------7\n");
	 printf("退出修改----------0\n");
 }
 //修改学生信息
 void Modify_stu(System1 **ps)
 {
	 assert((*ps) != NULL);
	 int ID = 0;
	 char name[MAX_NAME];
	 int a = 0;
	 int ret = 0;
	 int b = 0;
	 int NewID;
	 char Newname[MAX_NAME];
	 char Newgender[MAX_GENDER];
	 char Newbirth[MAX_BIRTH];
	 char NewAddr[MAX_Addr];
	 char NewTel[MAX_TELE];
	 char NewE_mail[MAX_MAIL];
	 if ((*ps)->stu_size == 0)
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
			 do
			 {
				 Modify_menu_stu();
				 printf("请选择:>");
				 scanf("%d", &b);
				 switch (b)
				 {
				 case Id:
					 printf("请输入学号:>");
					 scanf("%d", &NewID);
					 (*ps)->stu_data[ret].ID = NewID;
					 break;
				 case NAME:
					 printf("请输入姓名:>");
					 scanf("%s", Newname);
					 strcpy((*ps)->stu_data[ret].name, Newname);
					 break;
				 case GENDER:
					 printf("请输入性别:>");
					 scanf("%s", Newgender);
					 strcpy((*ps)->stu_data[ret].gender, Newgender);
					 break;
				 case BIRTH:
					 printf("请输入出生日期:>");
					 scanf("%s", Newbirth);
					 strcpy((*ps)->stu_data[ret].birth, Newbirth);
					 break;
				 case ADDR:
					 printf("请输入出生地址:>");
					 scanf("%s", NewAddr);
					 strcpy((*ps)->stu_data[ret].Addr, NewAddr);
					 break;
				 case TEL:
					 printf("请输入电话:>");
					 scanf("%s", NewTel);
					 strcpy((*ps)->stu_data[ret].Tel, NewTel);
					 break;
				 case E_MAIL:
					 printf("请输入邮箱:>");
					 scanf("%s", NewE_mail);
					 strcpy((*ps)->stu_data[ret].E_mail, NewE_mail);
					 break;
				 case EXIT:
					 printf("退出修改\n");
					 break;
				 default:
					 printf("输入错误，请重新输入\n");
					 break;
				 }
			 } while (b);
		 }
	 }
 }
//查找学生信息
 void Search_stu(const System1 **ps)
 {
	 assert((*ps) != NULL);
	 char name[MAX_NAME];
	 int n = 0;
	 int ID=0;
	 int ret = 0;
	 if ((*ps)->stu_size == 0)
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
			 printf("   %-12s\t%-10s\t%-12s\t%-10s\t%-25s\t%-20s\t%-30s\n", "学号", "姓名", "性别", "出生年月", "住址", "电话号码", "邮箱");
			 printf("%d. %-12d\t%-10s\t%-12s\t%-10s\t%-25s\t%-20s\t%-30s\n",ret+1,
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
 void Print_stu(const System1 **ps)
 {
	 int i = 0;
	 assert((*ps)!=NULL);
	 if ((*ps)->stu_size == 0)
	 {
		 printf("暂无学生信息！\n");
	 }
	 else
	 {
		 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		 printf("   %-12s\t%-10s\t%-5s\t%-10s\t%-25s\t%-20s\t%-25s\n", "学号", "姓名", "性别", "出生年月", "住址","电话号码","邮箱");
		 for (i = 0; i < (*ps)->stu_size; i++)
		 {
			 printf("%d. %-12d\t%-10s\t%-5s\t%-10s\t%-25s\t%-20s\t%-25s\n", i + 1,
				 (*ps)->stu_data[i].ID,
				 (*ps)->stu_data[i].name,
				 (*ps)->stu_data[i].gender,
				 (*ps)->stu_data[i].birth,
				 (*ps)->stu_data[i].Addr,
				 (*ps)->stu_data[i].Tel,
				 (*ps)->stu_data[i].E_mail);
		 }
		 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	 }
 }
 void Course_infor_menu()
 {
	 //system("cls");
	 printf("-----------------------------------------------\n");
	 printf("************     课程信息维护      ************\n");
	 printf("************    1.添加课程信息     ************\n");
	 printf("************    2.删除课程信息     ************\n");
	 printf("************    3.修改课程信息     ************\n");
	 printf("************    4.查找课程信息     ************\n");
	 printf("************    5.课程信息总览     ************\n");
	 printf("************    0.退出             ************\n");
	 printf("-----------------------------------------------\n");
 }
 //课程信息维护
 void Course_information(System2 *pc)
 {
	 assert(pc != NULL);
	 int choice = 0;
	 do
	 {
		 Course_infor_menu();
		 printf("请选择:>");
		 scanf("%d", &choice);
		 switch (choice)
		 {
		 case ADD:
			Add_course(&pc);
			 break;
		 case DEL:
			 Del_course(&pc);
			 break;
		 case MODIFY:
			 Modify_course(&pc);
			 break;
		 case SEARCH:
			 Search_course(&pc);
			 break;
		 case PRENSENT:
			 Print_course(&pc);
			 break;
		 case EXIT:
			 break;
		 default:
			 printf("输入错误，请重新输入!\n");
			 break;
		 }
	 } while (choice);
 }
 //初始化课程信息(动态内存分配)
 void Init_Course_data(System2 *pc)
 {
	 assert(pc != NULL);
	 pc->course_data = (Course_infor *)calloc(DEFAULT_SZ, sizeof(Course_infor));
	 if (pc== NULL)
	 {
		 printf("%s",strerror(errno));
		 return;
	 }
	 else
	 {
		 pc->course_size = 0;
		 pc->course_capacity = DEFAULT_SZ;
	 }
 }
 //判断course_data是否已满并修正动态分配的空间
 void Isfull_course(System2 *pc)
 {
	 assert(pc != NULL);
	 if (pc->course_size == pc->course_capacity)
	 {
		 //course_data已满则加5个容量
		 pc->course_data = (Course_infor *)realloc(pc->course_data, (pc->course_capacity + 5)*sizeof(Course_infor));//修正动态分配的空间
		 if (pc != NULL)
		 {
			 (pc->course_capacity) = (pc->course_capacity) + 5;
			 printf("扩容成功\n");
		 }
		 else
		 {
			 printf("扩容失败\n");
			 printf("%s", strerror(errno));
			 return;
		 }
	 }
 }
 //添加课程信息
 void Add_course(System2 **pc)
 {
	 system("cls");
	 assert((*pc) != NULL);
	 Isfull_course(*pc);
	 printf("请输入课程号：>");
	 scanf("%d", &((*pc)->course_data[(*pc)->course_size].course_NO));
	 printf("请输入课程名：>");
	 scanf("%s", (*pc)->course_data[(*pc)->course_size].course_name);
	 printf("请输入课程学分：>");
	 scanf("%d", &((*pc)->course_data[(*pc)->course_size].course_credit));
	 (*pc)->course_size ++;
	 printf("添加成功\n");
 }
 //按课程号查找课程
 static int Find_by_NO(const System2* pc, int NO)
 {
	 assert(pc != NULL);
	 int i = 0;
	 for (i = 0; i < pc->course_size; i++)
	 {
		 if (pc->course_data[i].course_NO == NO)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 static int Find_by_course_name(const System2* pc, char* name)
 {
	 assert(pc != NULL);
	 assert(name != NULL);
	 int i = 0;
	 for (i = 0; i < pc->course_size; i++)
	 {
		 if (strcmp(pc->course_data[i].course_name,name)==0)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 //删除课程信息
 void Del_course(System2 **pc)
 {
	 assert((*pc) != NULL);
	 char course_name[MAX_NAME];
	 int n = 0;
	 int course_NO = 0;
	 int ret = 0;
	 if ((*pc)->course_size == 0)
	 {
		 printf("暂无课程信息\n");
	 }
	 else
	 {
		 printf("按课程号删除------1\n");
		 printf("按课程名删除------2\n");
		 do
		 {
			 printf("请选择:>");
			 scanf("%d", &n);
			 if (n == 1)
			 {
				 printf("请输入要删除的课程的编号:>");
				 scanf("%d", &course_NO);
				 ret = Find_by_NO((*pc), course_NO);
				 break;
			 }
			 else if (n == 2)
			 {
				 printf("请输入要删除的课程的名字:>");
				 scanf("%s", course_name);
				 ret = Find_by_course_name((*pc),course_name );
				 break;
			 }
			 else
			 {
				 printf("输入错误，请重新输入！\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("无此课程！\n");
		 }
		 else
		 {
			 memmove(&((*pc)->course_data[ret]), &((*pc)->course_data[ret + 1]), ((*pc)->course_size)*sizeof((*pc)->course_data[0]));
			 (*pc)->course_size--;
			 printf("删除成功！\n");
		 }
	 }
 }
 //修改课程信息菜单
 void Modify_menu_course()
 {
	 system("cls");
	 printf("修改课程号  ----------1\n");
	 printf("修改课程名  ----------2\n");
	 printf("修改课程学分----------3\n");
	 printf("退出修改    ----------0\n");
 }
 //修改课程信息
 void Modify_course(System2 **pc)
 {
	 assert((*pc) != NULL);
	 int a = 0;
	 int b = 0;
	 int NewNO;
	 char Newname[MAX_NAME];
	 int Newcredit;
	 int ret = 0;
	 if ((*pc)->course_size == 0)
	 {
		 printf("暂无课程信息\n");
	 }
	 else
	 {
		 printf("按课程号查找------1\n");
		 printf("按课程名查找------2\n");
		 do
		 {
			 printf("请选择:>");
			 scanf("%d", &a);
			 if (a == 1)
			 {
				 printf("请输入要修改的课程的编号:>");
				 scanf("%d", &NewNO);
				 ret = Find_by_NO((*pc), NewNO);
				 break;
			 }
			 else if (a == 2)
			 {
				 printf("请输入要修改学生的姓名:>");
				 scanf("%s", Newname);
				 ret = Find_by_course_name((*pc), Newname);
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
			 
			 do
			 {
				 Modify_menu_course();
				 printf("请选择:>");
				 scanf("%d", &b);
				 switch (b)
				 {
				 case COURSENO:
					 printf("请输入课程号:>");
					 scanf("%d", &NewNO);
					 (*pc)->course_data[ret].course_NO = NewNO;
					 break;
				 case COURSENAME:
					 printf("请输入课程名:>");
					 scanf("%s", Newname);
					 strcpy((*pc)->course_data[ret].course_name, Newname);
					 break;
				 case COURSECREDIT:
					 printf("请输入学分:>");
					 scanf("%d", &Newcredit);
					 (*pc)->course_data[ret].course_credit = Newcredit;
					 break;
				 case EXIT:
					 printf("退出修改\n");
					 break;
				 default:
					 printf("输入错误，请重新输入\n");
					 break;
				 }
			 } while (b);
		 }
	 }
 }
 //查找课程信息
 void Search_course(const System2 **pc)
 {
	 assert((*pc) != NULL);
	 char course_name[MAX_NAME];
	 int n = 0;
	 int course_NO = 0;
	 int ret = 0;
	 if ((*pc)->course_size == 0)
	 {
		 printf("暂无课程信息\n");
	 }
	 else
	 {
		 printf("按课程号查找------1\n");
		 printf("按课程名查找------2\n");
		 do
		 {
			 printf("请选择:>");
			 scanf("%d", &n);
			 if (n == 1)
			 {
				 printf("请输入要查找的课程的编号:>");
				 scanf("%d", &course_NO);
				 ret = Find_by_NO((*pc), course_NO);
				 break;
			 }
			 else if (n == 2)
			 {
				 printf("请输入要查找的课程的名字:>");
				 scanf("%s", course_name);
				 ret = Find_by_course_name((*pc), course_name);
				 break;
			 }
			 else
			 {
				 printf("输入错误，请重新输入！\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("无此课程！\n");
		 }
		 else
		 {
			 printf("----------------------------------------------------------\n");
			 printf("   %-12s\t%-25s\t%-6s\n", "课程号", "课程名", "课程学分");
			 printf("%d. %-12d\t%-25s\t%-6d\n",ret+1,
				 (*pc)->course_data[ret].course_NO,
				 (*pc)->course_data[ret].course_name,
				 (*pc)->course_data[ret].course_credit);
			 printf("----------------------------------------------------------\n");
		 }
	 }
 }
 //显示课程信息
 void Print_course(const System2 **pc)
 {
	 int i = 0;
	 assert((*pc) != NULL);
	 if ((*pc)->course_size == 0)
	 {
		 printf("暂无课程信息！\n");
	 }
	 else
	 {
		 printf("----------------------------------------------------------\n");
		 printf("   %-12s\t%-25s\t%-6s\n", "课程号", "课程名", "课程学分");
		 for (i = 0; i < (*pc)->course_size; i++)
		 {
			 printf("%d. %-12d\t%-25s\t%-6d\n",i+1,
				 (*pc)->course_data[i].course_NO,
				 (*pc)->course_data[i].course_name,
				 (*pc)->course_data[i].course_credit);
		 }
		 printf("----------------------------------------------------------\n");
	 }
 }
