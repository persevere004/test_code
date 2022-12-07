#define  _CRT_SECURE_NO_WARNINGS  1
#define ROW  3
#define COL  3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//声明
void Initboard(char board[ROW][COL], int row, int col);
void Display(char board[ROW][COL],int row,int col);
void Playermove(char board[ROW][COL],int row,int col);
void Computermove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL],int row, int col);
//p 玩家赢
//c电脑赢
//q平局