/*
QuickSort(A[l~r])
//对子数组排序
//输入：数组A[0~n]的一个子序列A[l~r]，0<=l<=r<=n
//输出：非降序排列的子数组A[l~r];

if l<r
    s=Partition(A[l~r])
    QuickSort(l~s-1)
    QuickSort(s+1~r)

HoarePartition(A[l~r])
//以第一个元素为中轴，将子数组划分
//输入：数组A[0~n]的一个子序列A[l~r]，0<=l<=r<=n
//输出：A[l~r]的划分，返回分裂点位置

i=l+1
j=r
while(i<=j)
    while(A[i]<A[l]&&i<=r)
        i++
    while(A[j]>A[l])
        j--

    swap(A[i],A[j])
swap(A[i],A[j]);
swap(A[l],A[j]);
return j

LomutoPartition(A[l~r])
//以第一个元素为中轴对子数组进行划分
//输入：数组A[0~n]的一个子序列A[l~r]，0<=l<=r<=n
//输出：A[l~r]的划分和中轴位置
s=l;
p=A[l];
for(i=l+1;i<=r;i++)
    if(A[i]<p)
        s++
        swap(A[i],A[s])
swap(A[l],A[s])
return s
*/
#include <iostream>
using namespace std;
//加入模板后至少在int float double有效
template<typename T> 
void QuickSort(T A[], int l,int h);
template <typename T>
int LomutoPartition(T A[], int l,int h);
template <typename T>
int HoarePartation(T A[], int l,int h);



int main()
{
	int nArr[] = { 1,4,3,6,2,7,9 };
	QuickSort(nArr, 0, 7);
	for (int i = 0; i < 7; i++)
		cout << nArr[i] << "\t";
	cout << endl;
	system("pause");
    return 0;
}

template<typename T>
void QuickSort(T A[], int l, int h)
{
	if (h-l>1 )
	{
		int s = LomutoPartition(A, l, h);
		QuickSort(A, l, s);
		QuickSort(A,s + 1, h);
	}
}

template<typename T>
int LomutoPartition(T A[], int l, int h)
{
	T p = A[l];
	int s = l;
	for (int i = l + 1; i < h; i++)
	{
		if (A[i] < p)
		{
			s++;
			swap(A[i], A[s]);
		}
	}
	swap(A[s], A[l]);
	return s;
}

template<typename T>
int HoarePartation(T A[], int l, int h)
{
	int i = l + 1;
	int j = h - 1;
	T p = A[l];
	while (i <= j)
	{
		while (A[i] < p)
			i++;
		while (A[j] > p)
			j--;
		swap(A[i], A[j]);
	}
	swap(A[i], A[j]);
	swap(A[l], A[j]);
	return j;
}
