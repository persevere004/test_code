#define  _CRT_SECURE_NO_WARNINGS  1
#include "contact.h"
void menu()
{
	printf("------------------------------------------------------\n");
	printf("*********1.增加联系人     2.删除联系人****************\n");
	printf("*********3.修改联系人     4.查找联系人****************\n");
	printf("*********5.显示联系人     6.排序      ****************\n");
	printf("*********0.退                       ****************\n");
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
		printf("请选择功能:>");
		scanf("%d", &input);
		getchar();//吸收换行符
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
			printf("已退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(2000);
			break;
		}
	} while (input);
	return 0;
}

