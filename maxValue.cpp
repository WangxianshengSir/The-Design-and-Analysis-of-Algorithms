#include <iostream>
#include <algorithm>
using namespace std;

int max_val(int c[],n)
{
    int F[n]={0};
    F[1]=c[0];
    for(int i=2;i<n;i++)
    {
        F[i]=max(c[i-1]+F[i-2],F[i-1]);

    }
        return F[n];
}
int main()
{

}
