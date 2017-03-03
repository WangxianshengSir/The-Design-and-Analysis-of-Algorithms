/*
从底至上生成排列的原理如下
对于生成{1,...,n}的所有n!个排列，使用减一技术可以这样思考
将该问题的规模减一就是生成(n-1)!个排列，假设这个较小的问题已经被解决了，
那我们可以把n插入到n-1个元素的每一种排列的n个位置里，并以此得到较大规模问题的解，每一种排列都是独一无二的，
且总数量为n(n-1)!=n!。
既可以从左向右插入也可以从右向左插入。
推荐一开始从右到左把n插入12...(n-1)的位置中，然后每处理一种排列就掉换方向。`书上说这样符合最小变化要求(minimal-change requirement)`

以n=3为例
开始  1
从右到左将2插入1   12  21
从右到左将3插入12  123 132 312
从右到左将3插入21  321 231 213


arrangeGenerate(n)
//用来生成排列的从底向上算法
//输入：正整数n
//输出：{1，2，3...n}所有排列的列表

初始化第一个排列为{1}并加入列表
while n还未插入
    方向标志flag=从右到左

    while 存在未处理的排列

        如果flag表示从右到左

            while   从右向左将i插入arr
                将排列加入到列表

        否则

            while   从左到右将i插入arr
                将排列加入到列表

        方向标志反转


难点
1.列表的表示方式
2.排列的表示方式
2.如何判断有未处理排列存在


解决办法
1.列表每次处理从前至后，处理之后原排列被舍弃，符合FIFO，因此使用queue作为列表
2.如果排列使用动态添加的方式只能使用标准库STL，无论使用哪个都很繁琐，这里使用指针数组，0下标不使用。
比如，排列{1}表示为01000....,这样插入实际就是交换位置
3.从排列的性质可以得到，每个内while循环里执行的次数由n决定，即n!,例如n=1，处理1个排列，n=2，处理两个排列，n=3，处理6个排列。。。。
并且每个原始排列处理后会被抛弃，所以每次内层循环完成后表中剩余的排列即为i个数的所有排列

*/
#include <iostream>
#include <queue>
using namespace std;


queue<int*> arrangeGenerate(int n)
{
	//列表
	queue<int*> arrQueue;
	//表示排列，下标为0的不用，方便运算
	int *arr = new int[n + 1];
	//千万不要忘记*sizeof()
	memset(arr, 0, (n + 1) * sizeof(int));
	//初始化第一个列表
	arr[1] = 1;
	arrQueue.push(arr);
	//下标为0不用，1已经加入到列表，从2开始
	int i = 2;
	//nTotal存储总排列数
	int nTotal = 1;



	while (i <= n)
	{
		bool flag = true;


		int count = nTotal;
		int* nesTempArr;
		while (count--)
		{
			//从前至后依次处理排列，并将处理过的排列舍弃
			arr = arrQueue.front();
			arrQueue.pop();

			//从右向左
			if (flag)
			{
				for (int j = 0; j<i; j++)
				{
					//第一次插入时直接将第i位赋值即可
					if (j == 0)
						arr[i] = i;
					else
					{
						//从右向左交换
						swap(arr[i - j], arr[i - j + 1]);

					}
					//将新生成的排列复制一份存入列表
					nesTempArr = new int[n + 1];
					memcpy(nesTempArr, arr, (n + 1) * sizeof(int));
					arrQueue.push(nesTempArr);
				}
			}
			else//从左向右
			{
				for (int j = 0; j<i; j++)
				{
					//第一次插入依次向右赶，空出arr[1]并赋为i
					if (j == 0)
					{
						for (int k = i - 1; k >= 1; k--)
						{
							arr[k + 1] = arr[k];
						}
						arr[1] = i;
					}
					else
					{
						//从左向右交换
						swap(arr[j], arr[j + 1]);
					}
					nesTempArr = new int[n + 1];
					memcpy(nesTempArr, arr, (n + 1) * sizeof(int));
					arrQueue.push(nesTempArr);
				}
			}
			//改变方向
			flag = !flag;
		}
		//更新排列总数
		nTotal *= i;
		i++;
	}
	return arrQueue;
}

int main()
{

	cout << "请输入要生成的组合位数: ";
	int n;
	cin >> n;
	queue<int*> resQueue(arrangeGenerate(n));
	int count = 0;
	int* arr;
	while(!resQueue.empty()) 
	{
		arr = resQueue.front();
		resQueue.pop();
		for (int i = 1; i <= n; i++)
			cout << arr[i];
		cout << "\n";
		count++;
		free(arr);
	}
	
	cout << "排列总数为: " << count << endl;
	system("pause");
	return 0;

}