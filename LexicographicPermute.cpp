/*
LexicographicPermute(n)
//以字典序生成排列
//输入：一个正整数n
//输出：在字典序下{1,2,3...n}所有排列的列表

初始化第一个排列为12...n
while 最后一个排列有两个连续升序的元素 do
找出使得a[i]<a[i+1]的最大的i//隐含条件是a[i+1]>a[i+2]>...>a[n]
找出使得a[i]<a[j]的最大索引j//j>=i+1,因为a[i]<a[i+1]
交换a[i]和a[j];//a[i+1~n]仍然保持降序
将a[i+1]到a[n]的元素反序
将这个新排列添加到列表中

解析
注意这里下标从1开始，0舍弃不用
举个例子 n=5时 
		1. arr={14325} 下一个是14352
		2. arr={14253} 下一个是14325
对于1 它没有降序排列(a[i+1]>a[i+2]>...>a[n]),或者说它的降序排列只有arr[n]，所以i=n-1(注：arr[i+1]=a[n]);
因为j肯定要大于i,令j=n,循环判断使a[i]<a[j]的最大索引j(循环条件是j>=i+1)，显然这里j=n,然后交换arr[i]和arr[j]，得到
{14352},再倒序arr[i+1~n]，这里i+1=n,也就是说说a[i+1~n]的倒序操作根本没有执行，
对于2 它的降序排列是arr[4~n]，所以i=3,同上令j=n,得到j=n,然后交换arr[i]和arr[j]，得到{14352}，最后倒序arr[4~n]即{52},执行
后变为{25}，最终得到{14325}

可以再用{12345}做下测试


*/
#include <iostream>
#include <vector>
using namespace std;
vector<int*> LexicographicPermute(int n)
{

	vector<int*> arrVector;
	int *arr = new int[n + 1];
	int i, j;
	for (i = 0; i <= n; i++)
		arr[i] = i;
	arrVector.push_back(arr);
	//第一个排列为完全升序，n>1时一定成立
	bool flag =n>1?true:false;
	int *tempArr;
	while (flag)
	{
		flag = false;

	
		//查找降序排列，找出i+1
		i = n;
		while (i > 1)
		{
			if (arr[i] < arr[i - 1])
				i--;
			else
				break;
		}

		//得到i
		i -= 1;
		
		//找出j
		j = n;
		while (j >= i + 1)
		{
			if (arr[j] > arr[i])
				break;
			else
				j--;
		}

		//交换i,j
		swap(arr[i], arr[j]);

		//倒序i+1~n
		j = n;
		i = i + 1;
		while (j - i>0)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		//将得到的排列存储到列表
		tempArr = new int[n + 1];
		memcpy(tempArr, arr, (n + 1) * sizeof(int));
		arrVector.push_back(tempArr);

		//循环继续条件：有两个连续升序的元素
		for (i = 1; i<n; i++)
			if (arr[i]<arr[i + 1])
			{
				flag = true;
				break;
			}
	}
	return arrVector;
}

int main()
{
	cout << "请输入排列的位数：";
	int n;
	cin >> n;
	int count = 0;
	vector<int*> arrVector(LexicographicPermute(n));

	for each (int* var in arrVector)
	{
		for (int i = 1; i <= n; i++)
			cout << var[i];
		free(var);
		cout << endl;
		count++;
	}
	cout << "共有排列：" << count << endl;
	system("pause");
	return 0;
}