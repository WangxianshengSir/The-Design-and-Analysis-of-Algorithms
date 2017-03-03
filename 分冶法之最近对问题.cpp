/*
给定一个点集，找出最近对的距离
如果用穷解法算法复杂度时O(n^2)
如果用分冶法，算法复杂度只有O(nLogn)
使用分冶法的原理如下

将点集按x轴排序得到P，按y轴排序得到Q，将P从x=P[n/2-1]=m(向上取整)分为P1,P2.
此时最近对的距离有三种情况
1. 在P1
2. 在P2
3. 在P1和P2交界处

首先假设P1和P2的最近对距离分别为d1,d2.d=Min{d1,d2},那3中的最近对范围为[m-d,m+d],
将Q中x范围为[m-d,m+d]的点复制到数组S,找出S中的最近对距离，最终得到最近对距离。
再对这一过程进行递归。

伪代码如下

EfficientClosestPair(P,Q)
//使用分冶算法求解最近点对问题
//输入：数组P储存了平面上的n>=2个点，并按照这些点的x轴坐标升序排列，
//数组Q存储了与P相同的点只是它按照这些点的y轴坐标升序排列
//输出：最近点对之间的欧几里得距离

if(n<=3)
    返回由蛮力算法求出的最小距离
else
    将P的[n/2]个点复制到P1(向上取整)
    将Q的前[n/2]个点复制到Q1(向上取整)
    将P中余下的点复制到P2
    将Q中余下的点复制到Q2
    d1<- EfficientClosestPair(P1,Q1)
    d2<-EfficientClosestPair(P2,Q2)
    d<-min{d1,d2}
    m<-P[n/2-1].x//向上取整
    将Q中所有|x-m|<d的点复制到数组S[0,num-1]
    dminsq<-d^2;
    for i<-0 to num-2 do
        k<-i+1
        while k<=num-1 and (S[k].y-S[i].y)^2 <dminsq
            dminsq<-min{((S[k].x-S[i].x)^2+(S[k].y-S[i].y)^2),dminsq}
            k<-K+1
    return sqrt(dminsq)
*/