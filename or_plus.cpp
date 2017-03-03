/*
题目描述：
给定x，k。求满足x+y=x|y的第k小的正整数y。
输入描述：
每组测试用例仅包含一组数据，每组数据为两个正整数x，k。满足0<x,k<2,000,000,000。
输出描述：
输出一个数y

输入样例：
5 1
输出样例
2
*/




/*
解析：


总结：
	1.找出符合x+y=x|y的模式
	2.找出符合第k小的模式



1.根据题目表述我们要先找到使x+y与x|y相等的条件，先不管k把样例化为二进制可以发现
	x:5 =	101
	y:1 =	010
嗯，取反。如果x=9呢
	x:9 =	1001
如果y=1 
	y:1 =	0001
此时x+y=10，x|y=9,不成立
如果y=2
	y:2 =	0010
此时x+y=11，x|y=11，成立
......

从上面的例子可以看出x+y=x|y的条件是(二进制时)只有当Xi=0时,Yi才能为1。(这个地方不知道怎么讲解，可以自己测试几个例子)

2.下面要考虑k了，第k小即符合x+y=x|y的y值的升序排列
	以x=9为例
	x:9 = 00001001
符合条件的y值为
		  00000010
		  00000100
		  00000110
		  00010010
		  00010100
		  00010110
		 ...... 
这里可以发现一个规律，如果把x为0位的相应的值以升序组成数组(长度应为31位，因为范围为2,000,000,000<2^31,可以看作去除符号位的int型)
		A[n]=2,4,16......
任意组合再按升序排列为
		B[2^n-1]2。4。2+4。16。16+2。16+4。16+2+4。
第1小即为2，第二小为4......
可以发现如果A的个数为n，那么B的个数为2^n-1(然而知道这点没用，根本用不上)

如何把k和这个数组(B)联系起来呢。
再举一个例子

	A[3]= 1 , 2 , 8
          0   1   2

	B[7]= 1 , 2 , 1+2 , 8 , 8+1 , 8+2 , 8+1+2
		  0   1    2    3    4     5      6
可以看出
	B[2]=B[0]+B[1]=A[0]+A[1]
	B[4]=B[3]+B[0]=A[2]+A[0]
	B[5]=B[3]+B[1]=A[2]+A[1]
	B[6]=B[3]+B[2]=A[2]+A[1]+A[0]
	
是不是发现了什么规律
B[2^l-1](l=0,1,2,3...)都为2^x(x=0,1,2...)。此时得到的就是结果
如果为B[2],B[4],B[5],B[6]，则需要进行递归相加
log(m)/log(2)表示以2为底的向下取整的对数，如log(8)/log(2)=3,log(9)/log(2)=3,log(10)/log(2)=3。
...（！！！一定要多测试一下，理解A和B的关系，刚才写解析的时候把自己给写晕了）

得到下列结论
	1.如果 m=0 ans=A[0],否则进入2
	2.如果 m+1=2^(log(m)/log(2)+1),answer=A[log(m)/log(2)+1] 否则进入3     (logm/log2 表示以2为底的对数，使用换底公式生成)
	3.answer=answer+A[log(m)/log(2)],m=m-2^(log(m)/log(2)),,回到1



代入一个数测试，如果m=6
	2.m+1=7!=8
	1.m!=0
	3.m=2,answer=0+A[2]=8,回到1
	1.m!=0
	2.m+1=3!=4
	3.answer=8+A[1]=10,m=0,回到1
	1.m=0,返回B[0],answer=10+A[0]=11


*/
/*
题目描述：
给定x，k。求满足x+y=x|y的第k小的正整数y。
输入描述：
每组测试用例仅包含一组数据，每组数据为两个正整数x，k。满足0<x,k<2,000,000,000。
输出描述：
输出一个数y

输入样例：
5 1
输出样例
2
*/
#include <iostream>
#include <math.h>
using namespace std;
const int MAX = 100;
long long int binary_x[MAX];
long long int binary_y[MAX];
void dec2binary(long long int dec, long long int binary[])
{
	int i = 0;
	while (dec != 0)
	{
		binary[i++] = dec % 2;
		dec /= 2;
	}

	while (i<MAX)
	{
		binary[i++] = -1;
	}
}
void produce_y()
{
	int j = 0;
	for (int i = 0; i<MAX; i++)
		if (binary_x[i] != 1)
			binary_y[j++] = pow((long long)2,(long long) i);

	while (j<MAX)
		binary_y[j++] = -1;

}

long long int recur_add(long long int m)
{
	
	if (m == 0)
		return binary_y[0];
	int b = log(m) / log(2) + 1;
	if (m + 1 == pow(2, b))
		return binary_y[b];
	else
		return binary_y[b-1] + recur_add(m - pow(2, b-1));

}


int main()
{
	int x, k;
	cin >> x >> k;
	dec2binary(x, binary_x);
	produce_y();
	cout << recur_add(k - 1);
	system("pause");
	return 0;
}
