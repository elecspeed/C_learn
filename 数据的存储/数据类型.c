#include <stdio.h>


//浮点数的存储(很复杂，且不经常用，只作了解)
//
//int main()
//{
//	int n = 9;
//	float* p_float = (float*) &n;
//	printf("int: %d\n", n);
//	printf("float: %f\n", *p_float);
//	
//	*p_float = 9.0;
//	printf("int: %d\n", n);
//	printf("float: %f\n", *p_float);
//	return 0;
//}
//
//任何一个二进制数浮点数可以表示为(-1)^S * M * 2^E
//如5.0 == 101.0
//		== 1.01 * 2^2
//		== (-1)^0 * 1.01 * 2^2
//
//其中(-1)^S表示符号位，S=0为正，S=1为负
//M表示有效数字，大于等于1，小于等于2
//2^E表示指数位
//
//IEEE 754规定：对于32位浮点数，最高位为S，接着8位为E，剩下的为M
//				对于64位浮点数，最高位为S，接着11位为E，剩下的为M
//因为 1<=M && M<2，即M可以写成1.xx的形式（其中xx是小数部分），即都有1。所以规定只保存xx
//规定：E为unsigned，存储时加上127（或1023）
//取出时三种情况：E全为0；E全为1；E不全为1或0（略）


//大小端
//大端存储模式：数据的低位保存在内存的高位，数据的高位保存在内存的低位
//小端存储模式：数据的低位保存在内存的低位，数据的高位保存在内存的高位
//本质是字节顺序的不同安排，另称为大（小）端字节序存储模式
//
//写程序判断当前机器的字节序
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int main()
//{
//	//使用函数判断当前机器的字节序
//	//返回1，小端
//	//返回0，大端
//	int a = check_sys();
//	if(a == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
//百度题


//整数的存储（包含char）
//原码，反码，补码
//正数的原反补相同，负数：~原码 == 反码（不包括符号位），反码 + 1 == 补码
//整数在内存中以补码的形式存储


//内置类型（即日常使用的int,char,double等，略）
//构造类型（数组，结构体，枚举，联合）
//指针类型
//空类型（void，通常用于函数返回类型，函数形参，指针类型void* p）


//数据类型
//意义：1.不同的数据类型开辟的内存空间不同；2.内存里存的二进制数，在不同数据类型下表现结果不同
//如：00100100在int类型下表现为36，在char类型下表现为$。
//
//int main()
//{
//	char a = 36;
//	int b = 36;
//	printf("%c %d\n", a, b);
//	
//	return 0;
//}
//注意：内存里存的只有也只能是二进制数，数据类型不同，则读取的方式不同，则表现结果不同

