#define  _CRT_SECURE_NO_WARNINGS  1
#include "contact.h"
void menu()
{
	printf("------------------------------------------------------\n");
	printf("*********1.������ϵ��     2.ɾ����ϵ��****************\n");
	printf("*********3.�޸���ϵ��     4.������ϵ��****************\n");
	printf("*********5.��ʾ��ϵ��     6.����      ****************\n");
	printf("*********0.��                       ****************\n");
	printf("------------------------------------------------------\n");
}
int main()
{
	struct contact con;
	Initcontact(&con);
	int input=0;
	do
	{
		menu();
		printf("��ѡ����:>");
		scanf("%d", &input);
		getchar();//���ջ��з�
		switch (input)
		{
		case ADD:
			Add(&con);
			break;
		case DEL:
			del(&con);
			break;
		case MODIFY:
			modify(&con);
			break;
		case SEARCH:
			search(&con);
			break;
		case PRINT:
			print(&con);
			break;
		case SORT:
			sort(&con);
			break;
		case EXIT:
			freedata(&con);
			printf("���˳�\n");
			break;
		default:
			printf("�����������������\n");
			Sleep(2000);
			break;
		}
	} while (input);
	return 0;
}

