#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	//下面的程序运行结果是什么
//	//int a[] = { 1,2,3,4 };
//	//printf("%zd\n", sizeof(a));		//16
//	//printf("%zd\n", sizeof(a + 0));	//4/8
//	//printf("%zd\n", sizeof(*&a));	//16
//	//printf("%zd\n", sizeof(&*a));	//4/8
//	
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	//printf("%zd\n", sizeof(arr));			//6
//	//printf("%zd\n", sizeof(arr + 0));		//4/8
//	//printf("%zd\n", sizeof(*arr));			//1
//	//printf("%zd\n", sizeof(&arr));			//4/8
//	//printf("%d\n", strlen(arr));			//随机值M
//	////printf("%d\n", strlen(*arr));			//error
//	//printf("%d\n", strlen(&arr));			//随机值M
//	//printf("%d\n", strlen(&arr + 1));		//随机值N，N+6==M
//
//	//如果换成char arr[] = "abcdef"; 呢？
//	//或者 char* p = "abcdef"; 呢？
//
//	//int b[3][4] = { 0 };
//	//printf("%zd\n", sizeof(b));				//48
//	//printf("%zd\n", sizeof(b[0]));			//16
//	//printf("%zd\n", sizeof(b[0] + 1));		//4/8，[0][1]的地址
//	//printf("%zd\n", sizeof(*(b[0] + 1)));	//4
//	//printf("%zd\n", sizeof(b + 1));			//4/8，第二行的地址
//	//printf("%zd\n", sizeof(*(b + 1)));		//16
//	//printf("%zd\n", sizeof(*b));			//16
//	//printf("%zd\n", sizeof(*(&b[0] + 1)));	//16
//	//printf("%zd\n", sizeof(b[3]));			//16
//
//	return 0;
//}

//程序运行结果是什么
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d\n", *(a + 1), *(ptr - 1));	//2,5
//	return 0;
//}

//程序运行结果是什么
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char arr[6];
//	short sCh[2];
//}*p;
////注：Test类型的大小为32字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);				//0x100020
//	printf("%p\n", (unsigned int*)p + 0x1);	//0x100004
//	printf("%p\n", (unsigned long)p + 0x1);	//0x100001
//
//	return 0;
//}

//程序运行结果是什么
int main()
{
	int a[4] = { 1,2,3,4 };
	int b = 0x11223344;
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((long long)a + 1);
	printf("%#x,%#x\n", ptr1[-1], *ptr2);	//

	return 0;
}