/*
 *找零问题：需找零金额为n，最少要用多少面值为d1<d2<...<dn的硬币
 */
#include <iostream>
using namespace std;

int ChangeMaking(int D[],int length,int n)
{
    int F[n+1];
    F[0]=0;
    for(int i=1;i<=n;i++)
    {
        int temp=D[length-1]+1;
        for(int j=1;j<length&&i>=D[j];j++)
            temp=min(F[i-D[j]],temp);
        F[i]=temp+1;
    }
    return F[n];
}

int main()
{
    int D[3]={1,3,4};
    cout<<ChangeMaking(D,3,6);
    return 0;
}
