/*
 *在n*m格木板中放有一些硬币，每格的硬币数目最多一个，在木板左上方的机器人要尽可能多的收集硬币，机器人只能向右、向下运动，找出机器人能找到的最大硬币数并给出相应的路径。
 */
#include<iostream>
using namespace std;
int RobotCollection(int M[][7],int row,int col)
{
    int F[row][col];
    F[1][1]=M[1][1];
    for(int j=2;j<col;j++)
       F[1][j]=F[1][j-1]+M[1][j];

    for(int i=2;i<row;i++)
    {
     F[i][1]=F[i-1][1]+M[i][1];
        for(int j=2;j<col;j++)
            F[i][j]=max(F[i][j-1],F[i-1][j])+M[i][j];
    }

 return F[row-1][col-1];
}
int main()
{
    int M[6][7]={
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0},
        {0,0,1,0,1,0,0},
        {0,0,0,0,1,0,1},
        {0,0,0,1,0,0,1},
        {0,1,0,0,0,1,0}
    };
    cout<<RobotCollection(M,6,7);
    return 0;


}
