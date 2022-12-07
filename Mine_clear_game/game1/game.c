#define  _CRT_SECURE_NO_WARNINGS  1
#include"game.h"
//void Initboard(char board[ROW][COL], int row, int col)
//{
//	int i, j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
void Display(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//打印一行数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割符
		if (i < row - 1)
		{
			for (i = 0; i < row - 1; i++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}		
	}
}
void Playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
		while (1)
		{
			printf("请输入坐标：>");
			scanf("%d %d", &x, &y);
			if (x >= 1 && x <= 3 && y >= 1 && y <= 3 && board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("输入坐标非法，请重新输入");
			}
		}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		x = rand()%3;
		y = rand()%3;
		srand(time(NULL));
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char Iswin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == '*')
				return 'p';
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == '#')
				return 'c';
	}
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == '*')
			return 'p';
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == '#')
			return 'c';
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == '*')
		return 'p';
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == '#')
		return 'c';
	for (int i = 0; i < row; i++)
	{
		int flag = 0;
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
				flag = 1;
		}
		if (flag == 0)
			return 'p';
	}
}
