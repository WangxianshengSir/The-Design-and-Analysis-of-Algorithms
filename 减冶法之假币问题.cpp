/*
分成两堆识别假硬币
    FakeCoins(硬币数组A[n])
//输入：硬币数组，值1表示真，值0表示假，有且只有一个假币
//输出：假币在原数组中的序号
initPos=0
while   n-initPos>1
    if (n-initPos)为偶数
        fir_end=(n+initPos)/2,mid=0,sec_start=(n+initPos)/2
    else
        fir_end=(n+initPos)/2,mid=(n+initPos)/2,sec_start=(n+initPos)/2+1
    
    if  A[initPos~fir_end-1]的和大于A[sec_start~n-1]
            if mid==0
                initPos=fir_end;
            else
                initPos=fir_end+1;
    else if 小于
            n=fir_end
    else
        return mid;
return -1;


*/
#include <iostream>
using namespace std;
int FakeCoins(int coins[],int n)
{
    int initPos=0;
    int fir_end,mid,sec_start,fir_sum,sec_sum;
    while(n-initPos>1)
    {
        if((n-initPos)%2==0)
        {
            fir_end==sec_start=(n+initPos)/2;
            mid=0;
        }
        else
        {
            fir_end=mid=(n+initPos)/2;
            sec_start=(n+initPos)/2+1;
        }

        fir_sum=sec_sum=0;
        for(int i=initPos,i<fir_end;i++)
            fir_sum+=coins[i];
        for(int i=sec_start,i<n;i++)
            sec_sum+=coins[i];

        if(fir_sum>sec_sum)
        {
            if(mid==0)
                init=fir_end;
            else
                init=fir_end+1;
        }
        else if(fir_sum<sec_sum)
        {
            n=fir_end;
        }
        else
            returm mid+1;
        
    }
    return -1;
}
int main()
{
    int coins[7]={1,1,1,0,1,1,1};
    cout<<FakeCoins(coins,7);
}