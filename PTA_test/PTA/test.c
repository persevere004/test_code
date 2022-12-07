#define  _CRT_SECURE_NO_WARNINGS  1
//#include <stdio.h>
//int main()
//{
//	int a, max = -10001;
//	while (scanf("%d", &a) != '\n')
//	{
//		if (a>max)
//			max = a;
//
//	}
//	printf("%d", max);
//
//}
//
//#include <stdio.h>
//int main()
//{
//	int a[] = { 0 }, b[] = { 0 };
//	int M, N, i=0, j=0;
//	scanf("%d", &M);
//	while (i < M){
//
//		scanf("%d ", &a[i]);
//		i++;
//	}
//	scanf("%d", &N);
//	while (i < N)
//	{
//		scanf("%d ", &b[i]);
//		i++;
//	}
//	for (i = 0; i<M; i++)
//	{
//		int flag = 0;
//		for (j = 0; j<N; j++)
//		{
//			if (a[i] == b[j])
//				flag = 1;
//		}
//		if (flag == 0)
//			printf("%d ", a[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[20], b[20], c[20];
//	int m, n, i, j, k = 0;
//	scanf("%d", &m);
//	for (i = 0; i<m; i++)
//		scanf("%d", &a[i]);
//	scanf("%d", &n);
//	for (i = 0; i<n; i++)
//		scanf("%d", &b[i]);
//	for (i = 0; i<m; i++){
//		for (j = 0; j<n; j++){
//			if (a[i] == b[j])
//				break;
//		}
//		if (j >= n){
//			c[k] = a[i];
//			k++;
//		}
//	}
//	for (i = 0; i<n; i++){
//		for (j = 0; j<m; j++){
//			if (b[i] == a[j])
//				break;
//		}
//		if (j >= m){
//			c[k] = b[i];
//			k++;
//		}
//	}
//	printf("%d", c[0]);
//	for (i = 1; i<k; i++){
//		for (j = 0; j<i; j++){
//			if (c[i] == c[j])
//				break;
//		}
//		if (j >= i)
//			printf(" %d", c[i]);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[20], b[20],c[20];
//	int M, N, i, j,k=0;
//	scanf("%d", &M);
//	for (i = 0; i<M; i++)
//		scanf("%d ", &a[i]);
//	scanf("%d", &N);
//	for (i = 0; i<N; i++)
//		scanf("%d ", &b[i]);
//	for (i = 0; i<M; i++)
//	{
//		for (j = 0; j<N; j++)
//		{
//			if (a[i] == b[j])
//			break;
//		}
//		if (j>=N)
//		{
//			c[k] = a[i];
//			k++;
//		}
//	}
//	for (i = 0; i<N; i++)
//	{
//		for (j = 0; j<M; j++)
//		{
//			if (b[i] == a[j])
//			{
//				break;
//			}
//		}
//		if (j>=M)
//		{
//			c[k] = b[i];
//			k++;
//		}
//	}
//	printf("%d", c[0]);
//	for (i = 1; i < k; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (c[i] == c[j])
//				break;
//		}
//		if (j >= i)
//			printf(" %d", c[i]);
//	}
//	return 0;
//#include <stdio.h>
//int main()
//{
//	int i, j, n, k, t, m;
//	int a[100];
//	scanf("%d %d", &n, &k);
//	for (i = 0; i<n; i++)
//		scanf("%d ", &a[i]);
//	for (i = 0; i < k; i++)
//	{
//		for (j = 0; j<n - i - 1; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//			}
//		}
//		if ((i + 1) == k)
//		{
//			printf("%d", a[0]);
//			for (i = 1; i < n; i++)
//				printf(" %d", a[i]);
//		}
//	}
//
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int m[6][6];
//	int n, r, c, flag, x, max = 0;
//	scanf("%d", &n);
//	for (r = 0; r<n; r++)
//	{
//		for (c = 0; c<n; c++)
//		{
//			scanf("%d ", &m[r][c]);
//		}
//	}
//	for (r = 0; r<n; r++)
//	{
//		for (c = 0; c<n; c++)
//		{
//			if (m[r][c]>max)
//			{
//				max = m[r][c];
//				flag = c;
//			}
//		}
//		int sign = 1;
//		for (x = 0; x<n; x++)
//		{
//			if (m[x][flag]<max)
//			{
//				sign = 0;
//				break;
//			}
//		}
//		if (sign == 1)
//		{
//			printf("%d %d", r, flag);
//			break;
//		}
//	}
//
//	return 0;
//}
//方阵循环右移
//#include <stdio.h>
//int main()
//{
//	int a[10][10], i, j, n, m;
//	scanf("%d %d", &m, &n);
//	for (i = 0; i<n; i++)
//	for (j = 0; j<n; j++)
//		scanf("%d", &a[i][j]);
//	m = m%n;
//	for (i = 0; i<n; i++)
//	{
//		for (j = n - m; j<n; j++)
//			printf("%d ", a[i][j]);
//		for (j = 0; j<n - m; j++)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
//	return 0;
//}
////矩阵相乘
//#include <stdio.h>
//int main()
//{
//	int a[100][100];
//	int b[100][100];
//	int c;
//	unsigned int Ra, Rb, Ca, Cb;
//	scanf("%d %d", &Ra, &Ca);
//	int i, j, k;
//	for (i = 0; i<Ra; i++)
//	{
//		for (j = 0; j<Ca; j++)
//			scanf("%d ", &a[i][j]);
//	}
//	scanf("%d %d", &Rb, &Cb);
//	for (i = 0; i<Rb; i++)
//	{
//		for (j = 0; j<Cb; j++)
//			scanf("%d ", &b[i][j]);
//	}
//	if (Ca != Rb)
//	{
//		printf("Error: %d != %d", Ca, Rb);
//		return 0;
//	}
//	else
//	{
//		printf("%d %d\n", Ra, Cb);
//		for (i = 0; i<Ra; i++)
//		{
//			if (i)
//				printf("\n");
//			for (j = 0; j<Cb; j++)
//			{
//				c = 0;
//				for (k = 0; k<Ca; k++)
//				{
//					c += a[i][k] * b[k][j];
//				}
//				if (j)
//					printf(" ");
//				printf("%d", c);
//			}
//		}
//	}
//	return 0;
//}
//#include<iostream>
//void move(char x, char y)
//{
//	printf("%c->%c\n", x, y);
//}
//void hanoi(int n, char from, char to, char by)
//{
//	if (n == 1)
//		move(from, to);
//	else
//	{
//		hanoi(n - 1, from, by, to);
//		move(from, by);
//		hanoi(n - 1, by, to, from);
//	}
//}
//using namespace std;
//
////输入n，输出将原来在A上的n个圆盘借助C移动到B上的移动过程，控制到文件尾
//int main() {
//	int n, cnt = 0;
//	while (cin >> n) {
//		cnt++;
//		if (cnt>1) cout << endl;
//		hanoi(n, 'A', 'B', 'C');
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int m, n, cnt = 0;
//	int a[51], j = 0;
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i<n; i++)
//		a[i] = 1;
//	for (int i = 0;; i++)
//	{
//		i %= n;
//		if (a[i] == 1)
//		{
//			cnt++;
//		}
//		if (cnt == m)
//		{
//			//j++;
//			printf("No %d: %d\n",++j, i+1);
//			cnt = 0;
//			a[i] = 0;
//		if (j == n-1)
//			break;
//		}
//	}
//	for (int k = 0; k < n; k++)
//	{
//		if (a[k] == 1)
//			printf("Last No is: %d\n", k + 1);
//	}
//	return 0;
//}
//#include <stdio.h>
//void strmcpy(char ch1[], char ch2[], int n)
//{
//	int i;
//	for (i = n - 1;; i++)
//	{
//		int j = 0;
//		ch2[j++] = ch1[i];
//		if (ch1[i] == '\0')
//		{
//			ch2[j] = '\0';
//			break;
//		}
//	}
//	for (i = 0; ch2[i] != '\0'; i++)
//	{
//		printf("%c", ch2[i]);
//	}
//
//}
//int main()
//{
//	int rpt, m;
//	char t[1001], s[1001] = { 0 };
//	scanf("%d", &rpt);
//	while (rpt)
//	{
//		gets(t);
//		scanf("%d", &m);
//		strmcpy(s, t, m);
//		rpt--;
//	}
//	return 0;
//}
//#include <stdio.h>
//void delchar(char ch[], char c)
//{
//	int j;
//	for (j = 0; ch[j] != '\0'; j++)
//	{
//		if (ch[j] != c)
//			printf("%c", ch[j]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char str[] = {0};
//	char a;
//	for (int i = 0; i<n; i++)
//	{    
//	    scanf("%c", str);
//		scanf("%c", &a);
//		delchar(str, a);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int mny = 0, sum = 0, change;
//	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
//	a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = 0;
//	while (1)
//	{
//		scanf("%d", &mny);
//		if (mny == -1)
//			break;
//		sum += mny;
//	}
//	int n = 0, cost = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == -1)
//			break;
//		switch (n)
//		{
//		case 1:cost += 1;
//			a1++;
//		case 2:cost += 1;
//			a2++;
//		case 3:cost += 1;
//			a3++;
//		case 4:cost += 2;
//			a4++;
//		case 5:cost += 2;
//			a5++;
//		case 6:cost += 3;
//			a6++;
//		case 7:cost += 3;
//			a7++;
//		case 8:cost += 3;
//			a8++;
//		case 9:cost += 4;
//			a9++;
//		case 10:cost += 4;
//			a10++;
//		}
//	}
//	if (cost>sum)
//		printf("Insufficient money");
//	else
//	{
//		printf("Total:%dyuan,change:%dyuan\n", sum, sum - cost);
//		if (a1)
//			printf("Table-water:%d;", a1);
//		if (a2)
//			printf("Table-water:%d;", a2);
//		if (a3)
//			printf("Table-water:%d;", a3);
//		if (a4)
//			printf("Coca-Cola:%d;", a4);
//		if (a5)
//			printf("Milk:%d;", a5);
//		if (a6)
//			printf("Beer:%d;", a6);
//		if (a7)
//			printf("Orange-Juice:%d;", a7);
//		if (a8)
//			printf("Sprite:%d;", a8);
//		if (a9)
//			printf("Onlong-Tea:%d;", a9);
//		if (a10)
//			printf("Green-Tea:%d;", a10);
//	}
//	return 0;
//}