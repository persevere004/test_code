#define  _CRT_SECURE_NO_WARNINGS  1
#include "game.h"
void menu()
{
	printf("***************************************\n");
	printf("******1.��ʼ��Ϸ  0.�˳���Ϸ***********\n");
	printf("***************************************\n");
}
void game()
{
	char board[ROW][COL];
	while (1)
	{
		int ret;
		Initboard(board[ROW][COL], ROW, COL);//��ʼ������
		Display(board[ROW][COL], ROW, COL);//��ӡ����
		Playermove(board[ROW][COL], ROW, COL);//����ƶ�
		ret=Iswin(board[ROW][COL], ROW, COL);//�ж���Ӯ
		Computermove(board[ROW][COL], ROW, COL);//�����ƶ�
		ret=Iswin(board[ROW][COL], ROW, COL);//�ж���Ӯ
	}
}
int main()
{	
	int input;
	do{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
				break;
		default:
			printf("�����������������\n");
				break;
		}
	} while (input);
	return 0;
}