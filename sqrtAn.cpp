/*
求a^n,以减冶法思想使用迭代每次将问题规模缩小一半
如果n为奇数，减一化为偶数并乘上底数即sqrt_W(a,n-1)*a;
如果n为偶数，n减半
输入 a,n
输出 a^n
*/
#include <iostream>
int sqrt_W(int a, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return sqrt_W(a, n / 2)*sqrt_W(a, n / 2);
	else 
		return sqrt_W(a, n - 1)*a;
}

int main()
{
	std::cout << sqrt_W(3, 4);
	system("pause");
	return 0;
}