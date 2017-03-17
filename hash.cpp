/*
 * hash_search
 */
#include <iostream>
#include <list>
using namespace std;
template <typename T>
struct Hash
{
    int length;
    list<T> *arr;
    Hash(int len,const T *src):length(len)
    {

        cout<<length<<endl;
        arr=new list<T>[length];
        for(int i=0;i<length;i++)
        {
            const T &a=src[i];
            arr[calhash(a)].push_back(a);
        }
    }
    Hash(int len):length(len)
    {
        arr=new list<T>[length];
    }
    int calhash(const T &a)
    {
        return a%length;
    }
    int search(const T &a)
    {
        int pos=calhash(a);
        list<T> &ser=arr[pos];

        for(typename list<T>::iterator beg=ser.begin();beg!=ser.end();beg++)
            if((*beg)==a)
                return pos;

        return -1;
    }
    void insert(const T &a)
    {
        arr[calhash(a)].push_back(a);
    }
    void print()
    {

        for(int i=0;i<length;i++)
        {
            cout<<i<<"\t";
            for(typename list<T>::iterator beg=arr[i].begin();beg!=arr[i].end();beg++)
            {
                cout<<*beg<<"\t";
            }
            cout<<endl;
        }
    }
};
int main()
{
    const int n=10;
    int arr[n]={1,2,3,4,5,6,7,8,15,26};
    Hash<int> ha(n,arr);
    ha.print();
    return 0;
}
