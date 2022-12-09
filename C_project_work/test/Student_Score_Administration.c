#define  _CRT_SECURE_NO_WARNINGS  1
#include "Student_Score_Administration.h" 
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
		 struct Stuinfor *p = (Stuinfor *)realloc(ps->stu_data, (ps->capacity + 2)*sizeof(System));//������̬����Ŀռ�
		 if (p != NULL)
		 {
			 (ps->capacity) = (ps->capacity) + 2;
			 ps->stu_data = p;
			 printf("���ݳɹ�\n");
		 }
		 else
		 {
			 printf("����ʧ��\n");
			 return;
		 }
	 }
}

 //���ѧ����Ϣ
 void Add_stu(System **ps)
 {
	 system("cls");
	 assert(*ps != NULL);
	 Isfull(*ps);
	 printf("������ѧ�ţ�>");
	 scanf("%d",&((*ps)->stu_data[(*ps)->size]).ID);
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
 //��ʾѧ����Ϣ
 void print(const System *ps)
 {
	 assert(ps!=NULL);
	 if (ps->size == 0)
	 {
		 printf("ͨѶ¼Ϊ��\n");
	 }
	 else
	 {
		 //printf("                       ͨѶ¼\n");
		 int i = 0;
		 printf("-------------------------------------------------------\n");
		 printf("   %-10s\t%-5s\t%-12s\t%-20s\t%-20s\t%-15s\t%-20s\n", "ѧ��", "����", "�Ա�", "��������", "סַ","�绰����","����");
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