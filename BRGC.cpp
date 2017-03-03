/*
binary reflected Gray code 二进制反射格雷码

伪代码描述
BRGC(n)
//递归生成n位的二进制反射格雷码
//输入：一个正整数n
//输出：所有长度为n的格雷码位串列表

if n=1,表L包含位串0和位串1
else 调用BRGC(n-1)生成长度为n-1的位串列表L1
把表L1倒序后复制给表L2
把0加到表L1中的每个位串前面
把1加到表L2中的每个位串前面
把表L2添加到表L1后面得到表L
return L;




在我看来这里的难点主要是
1.位串和表的存储结构
2.位串的动态添加
3.倒序复制操作



下面逐个击破
1.因为位串需要动态添加位数，并且需要在前方添加，因此使用list，表需要进行倒序复制，也可以使用list，但是为了避免混淆，这里使用vector
2.使用了list之后添加就很方便了
3.使用vector的反向迭代器进行倒序复制







总结，出现了一些小问题
1.错用list的构造函数
	BitString zero(0)
	BitString one(1)
不能这样用这个是用来分配存储空间的,这里表示分配0个int型存储空间,导致后面zero的容量为0，one的容量为1，并且其值被默认初始化为0

2.错用for each
for each里的参数都是拷贝复制过来的，导致位串的位数总是1，因为再foreach里添加位数之后那个临时位串就被销毁了，没有对原位串造成任何改变
*/


#include <vector>
#include <list>

typedef vector<list<int>> VList;

VList BRGC(int n)
{
	VList L;
	if (n == 1)
	{
		list<int> zero,one;
		zero.push_front(0);
		one.push_front(1);
		L.push_back(zero);
		L.push_back(one);
	}
	else
	{
		VList L1;
		L1 = BRGC(n - 1);
		//使用list的接受迭代器范围的构造函数初始化L2
		VList L2(L1.rbegin(), L1.rend());
		for(VList::iterator beg=L1.begin();beg!=L1.end();beg++)
		{
			(*beg).push_front(0);
		}
		for (VList::iterator beg = L2.begin(); beg != L2.end(); beg++)
		{
			(*beg).push_front(1);
		}
		L.insert(L.end(), L1.begin(), L1.end());
		L.insert(L.end(),L2.begin(), L2.end());

	}

	return L;
}

int main()
{
	int n;
	cout << "please input the length of bit string :";
	cin >> n;

	VList L = BRGC(5);
	int count = 0;
	for each (list<int> var in L)
	{
		for each (int bit in var)
		{
			cout << bit;
			
		}
		cout << "\n";
		count++;
	}
	cout <<"总位串数为："<< count<<endl;
	system("pause");
	return 0;
	
}