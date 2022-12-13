#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h" 
//ѧ����Ϣά��ϵͳ���ܲ˵�
void stuinfor_menu()
{
	//system("cls");
	printf("-----------------------------------------------\n");
	printf("************     ѧ����Ϣά��      ************\n");
	printf("************    1.���ѧ����Ϣ     ************\n");
	printf("************    2.ɾ��ѧ����Ϣ     ************\n");
	printf("************    3.�޸�ѧ����Ϣ     ************\n");
	printf("************    4.����ѧ����Ϣ     ************\n");
	printf("************    0.�˳�             ************\n");
	printf("-----------------------------------------------\n");
}
//ѧ����Ϣά��
void Student_information(System *ps)
{
	assert(ps != NULL);
	int choice = 0;
	do
	{
		stuinfor_menu();
		printf("��ѡ��>");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case ADD_STU:
		    Add_stu(&ps);//���ѧ����Ϣ
			break;
		case DEL_STU:
			Del_stu(&ps);
			break;
		case MODIFY:
			Modify_stu(&ps);
			break;
		case SEARCH:
			Search_stu(&ps);//����ѧ����Ϣ
			break;
		case Exit:
			break;
		default:
			printf("����������������룡\n");
			break;
		}

	} while (choice);
	
}

//��ʼ��ѧ����Ϣ�ṹ�壨��̬�����ڴ棩
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

 //�ж�stu_data�Ƿ�����
 void Isfull(System  *ps)
{
	 assert(ps != NULL);
	 if (ps->size == ps->capacity)
	 {
		 ps->stu_data = (Stuinfor *)realloc(ps->stu_data, (ps->capacity + 2)*sizeof(Stuinfor));//������̬����Ŀռ�
		 if (ps != NULL)
		 {
			 (ps->capacity) = (ps->capacity) + 2;
			// ps->stu_data = p;
			 printf("���ݳɹ�\n");
		 }
		 else
		 {
			 printf("����ʧ��\n");
			 return;
		 }
	 }
}
 //����������ѧ��
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
 //��ѧ�Ų���ѧ��
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
 //���ѧ����Ϣ
 void Add_stu(System **ps)
 {
	 system("cls");
	 assert(*ps != NULL);
	 Isfull(*ps);
	 printf("������ѧ�ţ�>");
	 scanf("%d", &((*ps)->stu_data[(*ps)->size]).ID);
	 printf("������������>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].name);
	 //gets((*ps)->stu_data[(*ps)->size].name);
	 printf("�������Ա�>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].gender);
	 //gets((*ps)->stu_data[(*ps)->size].gender);
	 printf("������������£�>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].birth);
	 printf("������סַ��>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].Addr);
	 //gets((*ps)->stu_data[(*ps)->size].Addr);
	 printf("������绰���룺>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].Tel);
	 //gets((*ps)->stu_data[(*ps)->size].Tel);
	 printf("���������䣺>");
	 scanf("%s", (*ps)->stu_data[(*ps)->size].E_mail);
	 //gets((*ps)->stu_data[(*ps)->size].E_mail);
	 (*ps)->size++;
	 printf("��ӳɹ�\n");
 }
 //ɾ��ѧ����Ϣ
 void Del_stu(System** ps)
 {
	 char name[MAX_NAME];
	 int n = 0;
	 int ID = 0;
	 int ret = 0;
	 if ((*ps)->size == 0)
	 {
		 printf("����ѧ����Ϣ\n");
	 }
	 else
	 {
		 printf("��ѧ��ɾ��------1\n");
		 printf("������ɾ��------2\n");
		 do
		 {
			 printf("��ѡ��:>");
			 scanf("%d", &n);
			 if (n == 1)
			 {
				 printf("������Ҫɾ��ѧ����ѧ��:>");
				 scanf("%d", &ID);
				 ret = Find_by_ID((*ps), ID);
				 break;
			 }
			 else if (n == 2)
			 {
				 printf("������Ҫɾ��ѧ��������:>");
				 scanf("%s", name);
				 ret = Find_by_name((*ps), name);
				 break;
			 }
			 else
			 {
				 printf("����������������룡\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("���޴��ˣ�\n");
		 }
		 else
		 {
			 memmove(&((*ps)->stu_data[ret]), &((*ps)->stu_data[ret + 1]), ((*ps)->size)*sizeof((*ps)->stu_data[0]));
			 (*ps)->size--;
			 printf("ɾ���ɹ���\n");
		 }
	 }
 }
 //�޸�ѧ����Ϣ�˵�
 void Modify_menu_stu()
 {
	 printf("�޸�ѧ��----------1\n");
	 printf("�޸�����----------2\n");
	 printf("�޸��Ա�----------3\n");
	 printf("�޸ĳ�������------4\n");
	 printf("�޸ĵ�ַ----------5\n");
	 printf("�޸ĵ绰----------6\n");
	 printf("�޸�����----------7\n");
 }
 //�޸�ѧ����Ϣ
 void Modify_stu(System **ps)
 {
	 char name[MAX_NAME];
	 int a = 0;
	 int ID = 0;
	 int ret = 0;
	 int b = 0;
	 if ((*ps)->size == 0)
	 {
		 printf("����ѧ����Ϣ\n");
	 }
	 else
	 {
		 printf("��ѧ�Ų���------1\n");
		 printf("�����ֲ���------2\n");
		 do
		 {
			 printf("��ѡ��:>");
			 scanf("%d", &a);
			 if (a == 1)
			 {
				 printf("������Ҫ�޸�ѧ����ѧ��:>");
				 scanf("%d", &ID);
				 ret = Find_by_ID((*ps), ID);
				 break;
			 }
			 else if (a == 2)
			 {
				 printf("������Ҫ�޸�ѧ��������:>");
				 scanf("%s", name);
				 ret = Find_by_name((*ps), name);
				 break;
			 }
			 else
			 {
				 printf("����������������룡\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("���޴��ˣ�\n");
		 }
		 else
		 {
			 Mpdify_menu_stu();
			 printf("��ѡ��:>");
			 scanf("%d", &b);
			 switch (b)
			 {
			 case Id:
				 printf("������ѧ��:>");
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
//����ѧ����Ϣ
 void Search_stu(const System **ps)
 {
	 char name[MAX_NAME];
	 int n = 0;
	 int ID=0;
	 int ret = 0;
	 if ((*ps)->size == 0)
	 {
		 printf("����ѧ����Ϣ\n");
	 }
	 else
	 {
		 printf("��ѧ�Ų���------1\n");
		 printf("�����ֲ���------2\n");
		 do
		 {
			 printf("��ѡ��:>");
			 scanf("%d", &n);
			 if (n == 1)
			 {
				 printf("������Ҫ����ѧ����ѧ��:>");
				 scanf("%d", &ID);
				 ret=Find_by_ID((*ps), ID);
				 break;
			 }
			 else if (n == 2)
			 {
				 printf("������Ҫ����ѧ��������:>");
				 scanf("%s", name);
				 ret=Find_by_name((*ps), name);
				 break;
			 }
			 else
			 {
				 printf("����������������룡\n");
			 }
		 } while (1);
		 if (ret == -1)
		 {
			 printf("���޴���!\n");
		 }
		 else
		 {
			 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			 printf(" %-12s\t%-10s\t%-12s\t%-10s\t%-25s\t%-20s\t%-30s\n", "ѧ��", "����", "�Ա�", "��������", "סַ", "�绰����", "����");
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
 //��ʾѧ����Ϣ
 void print(const System *ps)
 {
	 assert(ps!=NULL);
	 if (ps->size == 0)
	 {
		 printf("����ѧ����Ϣ��\n");
	 }
	 else
	 {
		
		 int i = 0;
		 printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		 printf("   %-12s\t%-10s\t%-5s\t%-10s\t%-25s\t%-20s\t%-25s\n", "ѧ��", "����", "�Ա�", "��������", "סַ","�绰����","����");
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