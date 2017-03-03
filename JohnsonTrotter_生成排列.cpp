
/*
JohnsonTrotter(n)
//实现用来生成排列的Johnson-Trotter算法
//输入：一个正整数n
//输出：{1,...,n}的所有排列的列表

将第一个排列初始化为A={1,2,...n}（方向都为左）
while 存在一个移动元素 do
求最大的移动元素k
把k和它箭头指向的相邻元素互换
调转所有大于k的元素的方向
将新排列添加到列表中

难点分析
1.如何确定移动元素的存在
2.最大移动元素如何求


解决办法
1.额外增加一个元素(A[0])做标志位，将k初始为1，while循环在k!=0时成立，进入循环后将k置零，如果不能找到移动元素则k为0，循环结束

2.分成方向为左和方向为右两种情况，对所有元素循环(i为下标)，方向为左时，i>1(防止越界),A[i]>A[i-1],A[i]>A[k](寻找最大移动元素)
方向为右时,i<n(防止越界)，A[i]>A[i+1]，A[i]>A[k],
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct unit
{
	int num;
	//false为左，true为右
	bool flag;
};
void Swap_W(unit &l, unit &r)
{
	unit t = l;
	l = r;
	r = t;

}
vector<vector<int>> JohnsonTrotter(int n)
{

	unit *l=new unit[n + 1];
	int *arrange=new int[n];//存储一个排列
	vector<vector<int>> mainArrangeVec;//存储所有排列
	int i;
	//初始排列
	for (i = 0; i <= n; i++)
	{
		l[i].num = i;
		l[i].flag = false;
	}

	//将类似1234的初始排列加入表中
	for (i = 1; i <= n; i++)
	{
		arrange[i - 1] = l[i].num;
	}
	vector<int> arrangeVec(arrange, arrange + n);
	mainArrangeVec.push_back(arrangeVec);

	int k = 1;
	//确定移动元素存在
	while (k != 0)
	{
		k = 0;
		//查找最大移动元素
		for (i = 1; i <= n; i++)
		{
			//方向为左
			if (l[i].flag == false)
			{
				if (i>1 && l[i].num>l[i - 1].num&&l[i].num>l[k].num)
					k = i;
			}
			else//方向为右
			{
				if (i<n&&l[i].num>l[i + 1].num&&l[i].num>l[k].num)
					k = i;
			}
		}
		//进行交换
		if (k != 0)
		{
			//与左侧元素交换
			if (l[k].flag == false)
			{
				Swap_W(l[k], l[k - 1]);
				k--;
			}
			else//与右侧元素交换
			{
				Swap_W(l[k], l[k + 1]);
				k++;

			}

			//改变对A[k]大的数的方向
			for (i = 1; i <= n; i++)
			{
				if (l[i].num>l[k].num)
				{
					l[i].flag = (l[i].flag ? false : true);
				}
			}
			//加入列表
			for (i = 1; i <= n; i++)
			{
				arrange[i - 1] = l[i].num;
			}
			vector<int> arrangeVec(arrange, arrange +n);
			mainArrangeVec.push_back(arrangeVec);	
		}
		
	}
	free(l);
	free(arrange);
	return mainArrangeVec;
}

int main()
{
	int n;
	int count = 0;
	cout << "please input arrange bits number: ";
	cin >> n;
	vector<vector<int>> arrangeVec(JohnsonTrotter(n));
	for each (vector<int> var in arrangeVec)
	{
		for each(int num in var)
		{
			cout << num;
		}
		cout << "\n";
		count++;
	}
	cout << "total arrange number：" << count << endl;
	system("pause");
	return 0;
}