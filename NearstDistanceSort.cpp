#include <iostream>
using namespace std;
template <typename T>
void NearstDistanceSort(T A[],int n)
{
    int Count[n]={0};
    for(int i=0;i<n;i++)
        cout<<Count[i];
    cout<<endl;
//calculate Count
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(A[i]<A[j])
                Count[j]=Count[j]+1;
            else
                Count[i]=Count[i]+1;
        }
    for(int i=0;i<n;i++)
        cout<<Count[i];
    cout<<endl;
// nearstSort
    for(int i=n-1;i>0;i--)
        for(int j=i-1;j>=Count[i];j--)
            if(Count[j]>=i)
            {
                swap(Count[j],Count[i]);
                cout<<(i-j)*2;
                break;
            }
//处理类似013245的情况
    for(int i=0;i<n-1;i++)
        if(Count[i]>Count[i+1])
            swap(Count[i],Count[i+1]);
        
    for(int i=0;i<n;i++)
        cout<<Count[i];
    cout<<endl;

}
int main()
{
    int A[6]={62,31,84,96,19,47};
    NearstDistanceSort(A,6);
    return 0;
}
