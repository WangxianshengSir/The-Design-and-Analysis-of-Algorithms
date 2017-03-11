/*
 *计数排序
 *算出列表中小于该元素的元素个数，并把结果记录在一张表中
 *，这个个数指出了该元素在有序列表中的位置
 *
 */

#include <iostream>
using namespace std;

template <typename T>
 T* ComparsionCountingSort(T A[],int n)
{
    int Count[n]={0};
    T *S=new T[n];
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(A[i]<=A[j])
                Count[j]++;
            else
                Count[i]++;
    for(int i=0;i<n;i++)
        S[Count[i]]=A[i];
    return S;
}

int main()
{
    int A[5]={1,4,3,2,6};
    int *p=ComparsionCountingSort(A,5);
    for(int i=0;i<5;i++)
        cout<<p[i];
    return 0;
}
