#define  _CRT_SECURE_NO_WARNINGS  1
//#include<assert.h>
#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int N, i, count = 0;
//	int score;
//	double sum = 0.0, average;
//	scanf("%d", &N);
//	for (i = 0; i<N; i++)
//	{
//		scanf("%d", &score);
//		if (score >= 60)
//		{
//			count++;
//		}
//		sum += score;
//	}
//	average = sum / N;
//	printf("average = %.1lf\n", average);
//	printf("count = %d", count);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int i, letter = 0, blank = 0, digit = 0, other = 0;
//	char N;
//	for (i = 0; i<10; i++){
//		scanf("%c", &N);
//		if (N >= 'A'&&N <= 'z')
//			letter++;
//		else if (N == ' ' || N == '\n')
//			blank++;
//		else if (N >= '0'&&N <= '9')
//			digit++;
//		else
//			other++;
//
//	}
//	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int Y, i, count = 0;
//	scanf("%d", &Y);
//	if (Y <= 2000 || Y>2100)
//		printf("Invalid year!");
//	for (i = 2001; i <= Y; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0)
//		{
//			printf("%d\n", i);
//			count++;
//		}
//		if (i % 400 == 0)
//			printf("%d\n", i);
//		count++;
//	}
//	if (Y>2000 && Y <= 2100 && count == 0)
//		printf("None");
//
//	return 0;
//}
//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c;
//	double x1, x2, x3, y1, y2, y3;
//	scanf("%d %d %d %d %d %d", &x1, &x2, &x3, &y1, &y2, &y3);
//	a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
//	b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
//	c = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y2));
//	double z = (a + b + c) / 2.0;
//	if ((a + b) > c && (a + c) > b)
//	{
//		double L, A;
//		A = sqrt(z*(z - a)*(z - b)*(z - c));
//		L = a + b + c;
//		printf("L = %.2lf ,A = %.2lf", L, A);
//	}
//	else
//		printf("Impossible");
//
//
//	return 0;
//}
//
//#include<stdio.h>
//#include <string.h>
//int main()
//{
//	char* a;
//	while (1)
//	{
//		scanf("%c", &a);
//		if (strcmp(a, "#")==0)
//			break;
//		printf("%c-%d", a, a);
//	}
//
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int y, m, d;
//	scanf("%4d/%02d/%02d", &y, &m, &d);
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//	{
//		switch (m)
//		{
//		case 1:printf("%d", d); break;
//		case 2:printf("%d", d + 31); break;
//		case 3:printf("%d", d + 60); break;
//		case 4:printf("%d", d + 91); break;
//		case 5:printf("%d", d + 121); break;
//		case 6:printf("%d", d + 152); break;
//		case 7:printf("%d", d + 182); break;
//		case 8:printf("%d", d + 213); break;
//		case 9:printf("%d", d + 244); break;
//		case 10:printf("%d", d + 274); break;
//		case 11:printf("%d", d + 305); break;
//		case 12:printf("%d", d + 335); break;
//		}
//	}
//	else
//	{
//		switch (m)
//		{
//		case 1:printf("%d", d); break;
//		case 2:printf("%d", d + 31); break;
//		case 3:printf("%d", d + 59); break;
//		case 4:printf("%d", d + 90); break;
//		case 5:printf("%d", d + 120); break;
//		case 6:printf("%d", d + 151); break;
//		case 7:printf("%d", d + 181); break;
//		case 8:printf("%d", d + 212); break;
//		case 9:printf("%d", d + 243); break;
//		case 10:printf("%d", d + 273); break;
//		case 11:printf("%d", d + 304); break;
//		case 12:printf("%d", d + 334); break;
//		}
//	}
//
//	return 0;
//}
//
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int n, i, j, k, count = 0, s = 0;
//	scanf("%d %d", &n, &k);
//	for (i = n; i>1; i--)
//	{
//		for (j = 2; j < sqrt((double)i); j++){
//			if (i%j == 0)
//				break;
//
//		}
//		if (j>sqrt((double)i))
//		{
//			printf("%d", i);
//
//			count++;
//			if (count<=k - 1)
//			{
//				printf("+");
//			}
//			else
//				printf("=");
//			s += i;
//		}
//
//		if (count == k)
//			break;
//	}
//	printf("%d", s);
//
//
//	return 0;
//}
//
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int N, x, y;
//	scanf("%d", &N);
//	for (x = 1; x <= sqrt((double)N); x++)
//	{
//		for (y = 1; y <= sqrt((double)N); y++)
//		{
//			if (x*x + y*y == N&&x <= y)
//				printf("%d %d\n", x, y);
//
//		}
//	}
//	return 0;
//}
//
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int N, x, y, count = 0;
//	scanf("%d", &N);
//	for (x = 1; x <= sqrt((double)N); x++)
//	{
//		for (y = 1; y <= sqrt((double)N); y++)
//		{
//			if (x*x + y*y == N&&x < y)
//			{
//
//				count++;
//				if (count == 1)
//				{
//					printf("%d %d", x, y);
//				}
//				else{
//					printf("\n");
//					printf("%d %d", x, y);
//
//				}
//			}
//			
//		}
//	}
//
//	if (count == 0)
//		printf("No solution");
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	char m;
//	int n, x;
//	scanf("%c %d", &m, &n);
//	n %= 26;
//	if (97 <= m + n && m + n <= 122)
//	{
//		printf("%c", m + n);
//	}
//	else if (97 > m + n)
//	{
//		printf("%c", m + n + 26);
//	}
//	else if (122 < m + n)
//	{
//		printf("%c", m + n - 26);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int n, i, j, k, count = 0, s = 0;
//	scanf("%d %d", &n, &k);
//	for (i = n; i>1; i--)
//	{
//		for (j = 2; j < sqrt((double)i); j++){
//			if (i%j == 0)
//				break;
//
//		}
//		if (j>sqrt((double)i))
//		{
//
//
//			count++;
//			if (count == 1)
//			{
//				printf("%d", i);
//
//			}
//			else
//			{
//				printf("+");
//				printf("%d", i);
//			}
//
//			s += i;
//		}
//
//		if (count == k)
//			break;
//	}
//	printf("=%d", s);
//
//
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	long long x[1000010];
//	int n, k;
//	while (~scanf("%d %d", &n, &k))
//	{
//		if (k == 3)
//		{
//			x[1] = 1;
//			x[2] = 2;
//			x[3] = 0;
//			for (int i = 4; i <= n; i++)
//			{
//				x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % 998244353;
//			}
//			printf("%d\n", x[n]);
//		}
//		else if (k == 1)
//		{
//			x[1] = 0;
//			x[2] = 1;
//			x[3] = 2;
//			for (int i = 4; i <= n; i++)
//			{
//				x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % 998244353;
//			}
//			printf("%d\n", x[n]);
//		}
//		else if (k == 2)
//		{
//			x[1] = 1;
//			x[2] = 0;
//			x[3] = 2;
//			for (int i = 4; i <= n; i++)
//			{
//				x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % 998244353;
//			}
//			printf("%d\n", x[n]);
//		}
//		else
//		{
//			x[1] = 1;
//			x[2] = 2;
//			x[3] = 4;
//			for (int i = 4; i <= n; i++)
//			{
//				if (i != k)
//					x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % 998244353;
//				else
//					x[i] = 0;
//			}
//			printf("%d\n", x[n]);
//		}
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int *p;
//	p = &a;
//	*p = 100;
//	printf("%d\n",*p );
//	return 0;
//}
//#include <stdio.h>
//struct Stu
//{
//	char name[10];
//	int age;
//	char sex[5];
//	double score;
//
//};
//    void set_age1(struct Stu stu)
//	{
//	stu.age = 18;
//     }
//	void set_age2(struct Stu* pStu)
//	{
//		pStu->age = 18;//结构成员访问
//	}
//	int main()
//	{
//		struct Stu stu;
//		struct Stu* pStu = &stu;//结构成员访问
//
//		stu.age = 20;//结构成员访问
//		set_age1(stu);
//		printf("%d\n", stu.age);
//
//		pStu->age = 20;//结构成员访问
//		set_age2(pStu);
//		printf("%d\n", pStu->age);
//		return 0;
//	}
//#include <stdio.h>
//int *test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int *p=test();
//	printf("%d", *p);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a =15.;
//	int count = 0;
//	for (int i = 0; i < 32;i++)
//	{
//		if ((( a >> i) & 1)==1)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//#include <stdio.h>
//double funpi(double n)
//{
//	double i;
//	double sum = 0, x = 0;
//	double flag = 1.0;
//	for (i = 1; 1 / (2 * i - 1)>n; i++)
//	{
//		x = flag / (2 * i - 1);
//		flag = -flag;
//		sum += x;
//	}
//	return 4 * sum;
//}
//int main()
//{
//	double e, pi;
//	scanf_s("%lf", &e);
//	pi = funpi(e);
//	printf("pi = %lf\n", 3.141793);
//	return 0;
//}
//#include <stdio.h>
//void print(int(*pa)[3], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", (*pa++)[j]);
//		}
//		printf("%p ", pa);
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[2][3] = { { 1, 2, 3 }, { 2, 3, 4 }};
//	print(arr, 2, 3);
//	int a1[] = { 1, 2, 3, 4};
//	int a2[] = { 2, 3, 4, 5 };
//	int *arr[] = { a1, a2 };
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", *(a1 + i));
//
//	}
//	printf("\n");
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%d ", *(a2 + i));
//
//		}
//
//	return 0;
//#include <stdlib.h>
//int compare(const void *elem1, const void *elem2)
//{
//	return *(int *)elem1 - *(int *)elem2;
//}
//int s(const void *elem1, const void *elem2)
//{
//	return (int)(*(float *)elem1 - *(float *)elem2);
//}
//void qsort(void *base, size_t num, size_t width, int(__cdecl *compare)(const void *elem1, const void *elem2));
//#include <stdio.h>
//int main()
//{
//	int a[10] = { 0, 1, 2, 2, 4, 5, 6, 4, 8, 9 };
//	float b[5] = { 1.0, 5.0, 6.0, 4.0, 8.0 };
//	int sz = sizeof(b) / sizeof(b[0]);
//	qsort(b, sz, sizeof(b[0]), s);
//	for (int i = 0; i < 5; i++)
//		printf("%.1f ", b[i]);
//	printf("\n");
//	return 0;
//}
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_by_name(const void *elem1, const void *elem2)
//{
//	return strcmp(((struct Stu*)elem1)->name,((struct Stu*)elem2)->name);
//}
//void swap(char*buf1, char*buf2,int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		char temp=*buf1;
//		 *buf1 = *buf2;
//		 *buf2 = temp;
//		 buf1++;
//		 buf2++;
//	}
//}
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* elem1,const void* elem2))
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
//			
//		}
//	}
//}
//int main()
//{
//	struct Stu s[3] = { { "zhangsan", 10 }, { "lishi", 20 }, { "wangwu", 30 } };
//	int s[] = { 5, 4, 2, 4, 5, 6 };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]),cmp_by_name);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", (s+i)->name);
//	}
//	return 0;
//}
//#include <string.h>
//#include <stdio.h>
//	/*int a[] = { 1, 2, 3, 4 };*/
//	/*printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a + 0));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(a[1]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", *&a);
//	printf("%d\n", sizeof(&a + 1));
//	printf("%d\n", sizeof(&a[0]));
//	printf("%d\n", sizeof(&a[0] + 1));*/
//	printf("%p \n", &a);
//	printf("%p \n", a);
//	printf("%p \n", a + 1);
//	printf("%p \n", &a + 1);
//	printf("%p \n", &a + 2);
//	/*char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };*/
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr + 0));
//	printf("%d\n", sizeof(*arr));
//	printf("%d\n", sizeof(arr[1]));
//	printf("%d\n", sizeof(&arr));
//	printf("%d\n", sizeof(&arr + 1));
//	printf("%d\n", sizeof(&arr[0] + 1));
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	printf("%d\n", strlen(*arr));
//	printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//		printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	/*char *p = "abcdef";
//	printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(p + 1));
//	printf("%d\n", sizeof(*p));
//	printf("%d\n", sizeof(p[0]));
//	printf("%d\n", sizeof(&p));
//	printf("%d\n", sizeof(&p + 1));
//	printf("%d\n", sizeof(&p[0] + 1));*/
//	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3 };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			printf("%p ", *(a + i) + j);
//		printf("\n");
//	}
//	struct Test
//	{
//		int Num;
//		char *pcName;
//		short sDate;
//		char cha[2];
//		short sBa[4];
//	}*p;
//	//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//	//已知，结构体Test类型的变量大小是20
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reverse(char *p, int m, int n)
//{
//		assert(p);
//		int len = strlen(p);
//		char *left = p + m - 1;
//		char *right = p + n - 1;
//		while (left < right)
//		{
//			char temp = *left;
//			*left = *right;
//			*right = temp;
//			left++;
//			right--;
//		}
//}
//void left_move(char *p, int k)
//{
//	assert(p);
//	int len = strlen(p);
//	for (int i = 0; i < k; i++)
//	{
//		char temp = *p;
//		for (int j = 0; j < len - 1; j++)
//		{
//			*(p+j) = *(p+j+1);
//		}
//		*(p+len-1) = temp;
//	}
//}
//void left_move(char *p, int k)
//{
//	assert(p);
//	int len = strlen(p);
//	reverse(p, 1, k);
//	reverse(p, k+1, len);
//	reverse(p, 1, len);
//}
//void right_move(char *p, int k)
//{
//	assert(p);
//	int len = strlen(p);
//	reverse(p, 1, len-k);
//	reverse(p, len-k+1, len);
//	reverse(p,1,len);
//}
//	int main()
//	{
//		char a[] = "abcdef";
//		int len = strlen(a);
//		int  step;		
//		scanf("%d",&step);
//		step %= len;
//		left_move(a, step);
//		right_move(a, step);
//		printf("%s", a);
//		return 0;
//	}
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//#include <stdlib.h>
//void My_strcat(char *str1, const char* str2)
//{ 
//	assert(str1);
//	assert(str2);
//	int len = strlen(str1);
//	str1 += len;
//	char temp = *str1;
//	while (*str2 != '\0')
//	{
//		*str1 = *str2;
//		*str2 = *str3;
//		str1++;
//		str2++;
//	}
//	*str1 = temp;
//
//}
//int my_strlen(char*p)
//{
//	if (*p == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(p + 1);
//}
//char* my_strcpy(char*dest, const char*src)
//{
//	assert(dest);
//	assert(src);
//	char *p = dest;
//	while (*dest++ = *src++);
//	return p;
//}
// char* my_strcat(char*dest, const char*src)
//{
//	assert(dest);
//	assert(src);
//	char*a = dest;
//	char *p = dest+strlen(dest);
//	while (*p++ = *src++);
//	return a;
//}
// char* my_strcat(char*dest, const char*src)
// {
//	 assert(dest);
//	 assert(src);
//	 char*a = dest;
//	 while (*dest)
//		 dest++;;
//	 while (*dest++ = *src++);
//	 return a;
// }
//int main()
//
//{
//	char a[100] = "abc";
//	char b[] = "aaaaaaa";
//	int len=my_strlen(b);
//	 char*p=my_strcat(a, b);
//	printf("%s", p);
//	int ret = strcmp(a, b);
//	printf("%d", ret);
//	/*printf("%d", len);*/
//	My_strcat(a, a);
//	strcat(a, a);
//	printf("%s\n", a);
//	printf("%s", b);
//	return 0;
//}
// void* my_memmove(void *dest, void  *src, size_t count)
// {
//	 void* ret = dest;
//	/* (dest + count - 1) > src&&*/
//	 if (dest < src)
//	 {
//		 while (count--)
//		 {
//			 *(char*)dest = *(char*)src;
//			 dest=(char*)dest+1;
//			 src=(char*)src+1;
//		 }
//	 }
//	 /*&& dest < src + count - 1*/
//	 if (((char*)dest + count - 1)>((char*)src + count - 1) )
//	 {
//		dest =(char*)dest+ count - 1;
//		 src = (char*)src+count - 1;
//		 while (count--)
//		 {
//			 *(char*)dest = *(char*)src;
//			dest=(char*) dest-1;
//			 src=(char*)src-1;
//		 }
//	 }
//	 return ret;
// }
// int main()
// {
//	 int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9,10};
//	 int sz = sizeof(a[0]);
//	void*b = my_memmove(a , a+2 , 16);
//	 for (int i = 0; i < 10; i++)
//	 {
//		 printf("%d ", *((int*)b+i));
//	 }
//	 return 0;
// }
// int judge()//判断计算机的大小端
// {
//
//	 int a=1;
//	 return (*(char*)&a);
// }
// int main()
// {
//	 int a = 1;
//	 int ret=judge();
//	 if (ret == 0)
//		 printf("大端\n");
//	 else
//		 printf("小端\n");
//	 return 0;
// }
// //qsort排序
// int cmp_int(const void *e1, const void* e2)
// {
//	 return  *(int*)e1 - *(int *)e2;
// }
// int cmp_char(const void *e1, const void* e2)
// {
//	 return *(char*)e1 - *(char*)e2;
// }
// int cmp_str(const void* e1, const void* e2)
// {
//	 return strcmp(*(char**)e1, *(char**)e2);
// }
// int main()
// {
//	 int i;
//	 char c[5][81] = { 0 };
//	 for (i = 0; i < 5; i++)
//	 {
//		 scanf("%s", c[i]);
//	 }
//	 qsort(c, 5, sizeof(c[0]), cmp_str);
//	 printf("After sorted:\n");
//	 for (i = 0; i<5; i++)
//		 printf("%s\n", c[i]);
//	 return 0;
// }
void main()
{
	printf("------------------------------------------------------\n");
	printf("*********1.增加联系人     2.删除联系人****************\n");
	printf("*********3.修改联系人     4.查找联系人****************\n");
	printf("*********5.显示联系人     6.排序      ****************\n");
	printf("*********7.保存通讯录     0.退出      ****************\n");
	printf("------------------------------------------------------\n");
}