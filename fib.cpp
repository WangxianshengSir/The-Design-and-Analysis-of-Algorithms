/*
 * 斐波那契实现
 * 如果只用计算F[n]，可以用如下公式
 * F[n]=1/sqrt(5)*(1.61803^n-(-0.61803)^n)
 * 详见算法设计与分析基础第二章
 */
#include <iostream>
using namespace std;
int* fib(int n)
{
    int *f=new int[n+1];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    cout<<f[n];
}
int main()
{
    fib(5);
    return 0;
}
