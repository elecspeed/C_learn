#include <stdio.h>





//练习，解释下列代码
//int arr[5];			//arr是数组，有5个元素，每个元素是int类型
//int *parr[5];			//parr是数组，有5个元素，每个元素是int*类型，（即parr是指针数组）
//int (*parr2)[5];		//parr2是数组指针，指向int数组，该数组有5个元素
//int *parr3[10][5];	//parr3是二维数组，每个元素是int*类型
//int (*parr4[10])[5];	//parr4是数组，有10个元素，每个元素是数组指针，该指针指向int数组，该数组有5个元素
//
//补充:去掉变量名即为变量的类型，数组除外。
//数组名为首元素地址，&数组名为数组地址


//数组指针，指向数组的指针
//int arr[10] = {0}; ------------- int (*p)[10] = &arr;		//&arr 和*p  
//char* arr2[5];	 ------------- char* (*p2)[5] = &arr2;	//&arr2和*p2 
//int arr3[2][5];    ------------- int (*p3)[5] = arr3;		//arr3 和*p3 
//int arr3[2][5];    ------------- int (*p4)[2][5] = &arr3;	//&arr3和*p4 
//
//
//用数组指针作形参，接收二维数组传参


//指针数组，存放指针的数组
//
//用指针数组管理多个数组
//int main()
//{
//	int arr1[] = {1, 2, 3};
//	int arr2[] = {4, 5, 6};
//	int arr3[] = {7, 8, 9};
//	int* parr[] = {arr1, arr2, arr3};
//	
//	return 0;
//}


//字符指针
//
//int main()
//{
//	//写法一
////	char arr[] = "abcdef";
////	char* pc = arr;
////	printf("%s\n", arr);
////	printf("%s\n", pc);
//	
//	//写法二
//	char* p = "abcdef";		//这里"abcdef"是常量字符串（意味着不能被改变）
//	printf("%s\n", p);
//	
//	printf("%c\n", *p);
//	*p = 'A';				//segmentation fault.
//	printf("%c\n", *p);
//
//	const char* p1 = "abcdef";	//准确写法	
//	
//	return 0;
//}
//注：C/C++用一个单独的内存区域来存常量字符串
//字符指针能够指向常量字符串，说明常量字符串一定存在于内存某处。
//
//int main()
//{
//	const char* p = "abcdef";
//	const char* p2 = "abcde";
//	const char* p3;
//	p3 = "abcd";
//	
//	printf("%p\n", p);
//	printf("%p\n", p2);
//	printf("%p\n", p3);
//	printf("%p\n", &"abcde");
//	return 0;
//}


//1.字符指针
//2.数组指针
//3.指针数组
//4.数组传参和指针传参
//5.函数指针
//6.函数指针数组
//7.指向函数指针数组的指针
//8.回调函数

