#include <iostream>
//余数实现
int gdc_remainder(int m,int n)
{
    int r;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
int swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}
int gdc_minus(int m,int n)
{
    if(m<n)
        swap(m,n);

    while(n!=0)
    {
        m=m-n;
        if(m<n)
            swap(m,n);
    }
    return m;
}
int main()
{

}