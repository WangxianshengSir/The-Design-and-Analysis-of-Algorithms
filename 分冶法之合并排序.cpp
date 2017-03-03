/*
    对于一个需要排序的数组A[0~n-1]，合并排序将它一分为二：A[0~[n/2]-1],A[[n/2]~n-1]（[n/2]向下取整）
    并对每一个子数组递归排序，然后把这两个排好序的子数组合并为一个有序数组
    MergeSort(A[0~n-1])
    //递归调用mergesort对数组A[0~n-1]排序
    //输入：一个可排序数组A[0~n-1]
    //输出：非降序排列的数组A[0~n-1]
    if(n>1)
        copy A[0~[n/2]-1] to B[0~[n/2]-1]
        copy A[[n/2]~n-1] to C[0~[n/2]-1]
        MergeSort(B[0~[n/2]-1])
        MergeSort(C[0~[n/2]-1])
        Merge(B,C,A)
    

    Merge(B[0~p-1],C[0~q-1],A[0~p+q-1])
    将两个有序数组合并为一个有序数组
    //输入：两个有序数组B[0~p-1],C[0~q-1]
    //输出：A[0~p+q-1]已经有序存放B和C中的元素
    i=0,j=0,k=0;
    while i<p and j<q do
        if B[i]<=C[j]
            A[k]=B[i];i++;
        else
            A[k]=C[j];j++;
        k++;
    
    if i==p
        copy C[j~q-1] to A[k~p+q-1]
    else copy B[i~q-1] to A[k~p+q-1]

Merge很好理解，因为B，C都是有序数组，从B，C的下标i=0,j=0开始，找出两个中较小的一个，加入到A，并移动相应的i或j到下一位置，
如果其中一个数组已经计算完毕，将另一个数组的剩余元素直接复制到A的尾部。

MergeSort可以思考当n=2时的情况
*/
#include <iostream>
using namespace std;
template<typename T>
void Merge(T *B, int p, T *C, int q, T *A);
template<typename T>
void MergeSort(T *A, const int n);

int main()
{
	const int n = 8;
	int A[n] = {2,5,7,4,3,1,8,9};

	MergeSort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << "\t";
	cout << endl;
	float fArr[n] = { 1.23f,3.54f,5.65f,7.56f,3.89f,9.87f,5.76f,5.43f };
	MergeSort(fArr, n);
	for (int i = 0; i < n; i++)
		cout << fArr[i] << "\t";
	cout << endl;
	system("pause");
	return 0;
}
template<typename T>
void MergeSort(T *A, const int n)
{
	if (n>1)
	{
		int nB = n / 2;//向下取正
		int nC = (n + 1) / 2;//取上取整
		T *B = new T[nB];
		T *C = new T[nC];
		memcpy(B, A, nB * sizeof(T));
		memcpy(C, A + nB, nC * sizeof(T));
		MergeSort(B, nB);
		MergeSort(C, nC);
		Merge(B, nB, C, nC, A);
	}
}
template <typename T>
void Merge(T *B, int p, T *C, int q, T *A)
{
	int i, j, k;
	i = j = k = 0;
	while (i < p&&j < q)
	{
		//由A分配给B的元素肯定在分配给C的元素之前，当B[i]==C[j]应该选择B中的元素，确保稳定性。
		if (B[i] > C[j])
			A[k++] = C[j++];
		else
			A[k++] = B[i++];
	}
	if (i == p)//B已到尽头
		memcpy(A + k, C + j, (q - j) * sizeof(int));
	else
		memcpy(A + k, B + i, (p - i) * sizeof(int));

	delete []B;
	delete []C;
	
}
