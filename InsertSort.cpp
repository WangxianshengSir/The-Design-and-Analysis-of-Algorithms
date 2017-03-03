/*
插入排序
自底至上使用迭代实现

认为A[0]是已排序，A[1~n-1]未排序
1次迭代将A[1]插入到已排序的数组A[0]中得到A[0~1]为已排序，A[2~n-1]未排序
n-1次迭代将A[n-1]插入到已排序的数组A[0~n-2]中得到非降序排列的数组A[0~n-1]

输入: n个可排序元素组成的数组A[0~n-1]
输出: 非降序排列的数组A[0~n-1]
*/
#include <iostream>
using namespace std;
void InsertSort(A[],n)
{
    for(int i=1;i<n;i++)
    int value=A[i];
    int j=i-1;
    while(j>=0&&A[j]>value)
    {
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=value;
    
}

int main()
{
    int A[]={5,3,6,4,1};
    InsertSort(A[],5);
    for(int i=0;i<5;i++)
    {
        cout<<A[i]<<endl;
    }
}