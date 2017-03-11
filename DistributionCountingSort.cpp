/*
 * 分布计数法只适用于待排序的元素只来自一个特定小集合的情况
 * 例如{7,6,8,7,6,7}，来自于集合{6,7,8}
 */
#include <iostream>
using namespace std;
template <typename T>
T* DistrubutionCountingSort(T A[],int n,int l,int u)
{
    int D[u-l+1]={0};
    T *S=new T[n];
    for(int i=0;i<n;i++)
        D[A[i]-l]++;
    for(int j=0;j<u-l;j++)
        D[j+1]+=D[j];
    for(int i=n-1;i>=0;i--)
    {
        int j=A[i]-l;
        S[D[j]-1]=A[i];
        D[j]--;
    }
    return S;
}

int main()
{
    int A[6]={13,11,12,13,12,12};
    int *p=DistrubutionCountingSort(A,6,11,13);
    for(int i=0;i<6;i++)
        cout<<p[i];
    return 0;
}
