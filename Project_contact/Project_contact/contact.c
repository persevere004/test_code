#define  _CRT_SECURE_NO_WARNINGS  1
#include "contact.h"
void Isfull(struct contact *ps);
void load_contact(struct contact *p)
{
	struct peoinfor temp = { 0 };
	FILE *pread = fopen("contact.dat", "rb");
	if (pread == NULL)
	{
		printf("load_contact::%s\n", strerror(errno));
	}
	while (fread(&temp, sizeof(struct peoinfor), 1, pread))
	{
		Isfull(p);
		p->data[p->size] = temp;
		p->size++;
	}
	fclose(pread);
	pread = NULL;
	
}
void Initcontact(struct contact *ps)
{
	ps->data = (struct peoinfor *)calloc(DEFAULT_SZ, sizeof(struct peoinfor));
	if (ps->data == NULL)
	{
		strerror(errno);
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	load_contact(ps);
    //memset(ps->data, 0, sizeof(ps->data));
	//ps->size = 0;
}
void Isfull(struct contact *ps)
{
	if (ps->size == ps->capacity)
	{
		struct peoinfor *p = (struct peoinfor *)realloc(ps->data, (ps->capacity + 2)*sizeof(struct peoinfor));
		if (p != NULL)
		{
			(ps->capacity) = (ps->capacity) + 2;
			ps->data = p;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
			return;
		}
	}
	
}
void Add(struct contact *ps)
{
	    Isfull(ps);
		printf("������������>");
		//scanf("%s", ps->data[ps->size].name);
		gets(ps->data[ps->size].name);
		printf("������绰��>");
		gets(ps->data[ps->size].tele);
		//scanf("%s", ps->data[ps->size].tele);
		printf("������סַ��>");
		gets(ps->data[ps->size].addr);
		//scanf("%s", ps->data[ps->size].addr);
		printf("�������Ա�>");
		gets(ps->data[ps->size].gender);
		//scanf("%s", ps->data[ps->size].gender);
		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));
		ps->size++;
		printf("��ӳɹ�\n");
}

void print(const struct contact *ps)
{
	//system("cls");
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("                       ͨѶ¼\n");
		int i = 0;
		printf("-------------------------------------------------------\n");
		printf("   %-5s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%d. %-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",i+1,
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].gender,
				ps->data[i].tele,
				ps->data[i].addr);
		}
		printf("-------------------------------------------------------\n");
	}
}

static int Find_by_name(const struct contact *ps,char *name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(name, ps->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void del(struct contact *ps)
{
	char name[NAME];
	printf("������Ҫɾ������ϵ�˵�����:>");
	scanf("%s", name);
	int ret=Find_by_name(ps, name);
	if (ret==-1)
	{
		printf("���޴���!\n");
	}
	else
	{
		/*int j = 0;
		for (j = i; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}*/
		memmove(&ps->data[ret], &ps->data[ret+ 1], (ps->size)*sizeof(ps->data[0]));
		ps->size--;
		printf("ɾ���ɹ�!\n");
	}
}

void search(const struct contact *ps)
{
	char name[NAME];
	printf("������Ҫ������ϵ�˵�����:>");
	scanf("%s", name);
	int ret = Find_by_name(ps, name);
	if (ret==-1)
	{
		printf("���޴���!\n");
	}
	else
	{
		printf("-------------------------------------------------------\n");
		printf("   %-5s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
			printf("%d. %-5s\t%-4d\t%-5s\t%-12s\t%-20s\n", ret + 1,
				ps->data[ret].name,
				ps->data[ret].age,
				ps->data[ret].gender,
				ps->data[ret].tele,
				ps->data[ret].addr);
		printf("-------------------------------------------------------\n");
	}

}
void modify(struct contact *ps)
{
	char name[NAME];
	printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf("%s", name);
	int ret = Find_by_name(ps, name);
	if (ret == -1)
	{
		printf("���޴���!\n");
	}
	else
	{
		int input = 0;
		char a[NAME];
		char b[GENDER];
		int c = 0;
		char d[TELE];
		char e[ADDRESS];
		printf("�޸�����------1\n");
		printf("�޸�����------2\n");
		printf("�޸ĵ绰------3\n");
		printf("�޸ĵ�ַ------4\n");
		printf("�޸��Ա�------5\n");
		printf("�˳��޸�------0\n");
		do
		{
			printf("��ѡ��:>");
			scanf("%d", &input);
			switch (input)
			{
			case Name:
				printf("����������:>");
				scanf("%s",a);
				strcpy(ps->data[ret].name,a );
				break;
			case Age:
				printf("����������:>");
				scanf("%d", &c);
				ps->data[ret].age;
				break;
			case Tele:
				printf("�������µ绰:>");
				scanf("%s", d);
				strcpy(ps->data[ret].tele, d);
				break;
			case Addr:
				printf("�������µ�ַ:>");
				scanf("%s", e);
				strcpy(ps->data[ret].addr, e);
				break;
			case Gender:
				printf("�������Ա�:>");
				scanf("%s", b);
				strcpy(ps->data[ret].gender, b);
				break;
			case Exit:
				printf("���˳��޸�!\n");
				break;
			default :
				printf("�����������������!\n");
				break;
			}
		} while (input);
		if (input>=Name&&input<=Gender)
		printf("�޸ĳɹ�!\n");
	}
}
int cmp_by_name(const void *e1, const void *e2)
{
	return strcmp(((struct contact *)e1)->data->name, ((struct contact *)e2)->data->name);
}

int cmp_by_age(const void* e1, const void* e2)
{
	return (((struct contact *)e1)->data->age) - (((struct contact *)e2)->data->age);
}

int cmp_by_tele(const void* e1, const void*e2)
{
	return strcmp(((struct contact *)e1)->data->tele, ((struct contact *)e2)->data->tele);
}
void swap(char*buf1, char*buf2,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		char temp=*buf1;
		 *buf1 = *buf2;
		 *buf2 = temp;
		 buf1++;
		 buf2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* elem1,const void* elem2))
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			
		}
	}
}
void sort(struct contact *ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
	}
	else
	{
		int input = 0;
		printf("����������-----1\n");
		printf("����������-----2\n");
		printf("���绰����-----3\n");
		printf("�˳�����  -----0\n");
		printf("��ѡ���������:>");
		scanf("%d", &input);
		switch (input)
		{
		case Name:
			bubble_sort(ps->data, ps->size, sizeof(struct peoinfor), cmp_by_name);
			break;
		case Age:
			bubble_sort(ps->data, ps->size, sizeof(struct peoinfor), cmp_by_age);
			break;
		case Tele:
			bubble_sort(ps->data, ps->size, sizeof(struct peoinfor), cmp_by_tele);
			break;
		case Exit:
			printf("���˳�����\n");
			break;
		default:
			printf("�������\n");
			break;
		}
		if (input >= Name&&input <= Tele)
		{
			printf("������ͨѶ¼:>\n");
			print(ps);
		}
	}
}
void freedata(struct contact*ps)
{
	free(ps->data);
	ps->data = NULL;
}
void save_contact(struct contact *ps)
{
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("save_contact::%s\n", strerror(errno));
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
	   fwrite(&ps->data[i], sizeof(struct peoinfor), 1, pfwrite);
		
	}
	fclose(pfwrite);
	pfwrite = NULL;
}