#define  _CRT_SECURE_NO_WARNINGS  1
#include "game.h"
void menu()
{
	printf("***************************************\n");
	printf("******1.开始游戏  0.退出游戏***********\n");
	printf("***************************************\n");
}
void game()
{
	char board[ROW][COL];
	while (1)
	{
		int ret;
		Initboard(board[ROW][COL], ROW, COL);//初始化棋盘
		Display(board[ROW][COL], ROW, COL);//打印棋盘
		Playermove(board[ROW][COL], ROW, COL);//玩家移动
		ret=Iswin(board[ROW][COL], ROW, COL);//判断输赢
		Computermove(board[ROW][COL], ROW, COL);//电脑移动
		ret=Iswin(board[ROW][COL], ROW, COL);//判断输赢
	}
}
int main()
{	
	int input;
	do{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
				break;
		default:
			printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}