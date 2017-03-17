/*
 *给定一排硬币，其面值均为正整数c1,c2...cn,这些整数并不一定两两不同，请问如何选择硬币，使得在其原始位置互不相邻的条件下，所选硬币的总金额最大
 */
#include <iostream>
#include <algorithm>
using namespace std;
int CoinRow(int c[],int n)//下标从1开始
{
    int F[n];
    F[0]=0;
    F[1]=c[1];

    for(int i=2;i<n;i++)
        F[i]=max(c[i]+F[i-2],F[i-1]);
    return F[n-1];
}

int main()
{
    int n=7;
    int c[n]={0,5,1,2,10,6,2};
    cout<<CoinRow(c,n);
    return 0;
}
