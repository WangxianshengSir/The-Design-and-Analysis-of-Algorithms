/*
 * Horspool(string pattern,string src)
 *Horspool算法实现字符串匹配
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;
const int ASCII=127;
//模式表
int TAB[ASCII];
void ShiftTable(string pattern)
{
    const int len=pattern.length();
    for(int i=0;i<ASCII;i++)
        TAB[i]=len;

    for(int j=0;j<len-1;j++)
        TAB[pattern[j]]=len-1-j;
}

int Horspool(string pattern,string src)
{
    const int pLen=pattern.length();
    const int sLen=src.length();
    ShiftTable(pattern);
    int i=pLen-1;
    while(i<=sLen-1)
    {
        int k=0;
        while(k<pLen&&pattern[pLen-1-k]==src[i-k])
            k++;
        if(k==pLen)
            return i-pLen+1;
        else
            i+=TAB[src[i]];
    }
    return -1;
}
int main()
{
    string s="efrggyvffeec";
    string p="vff";
    cout<<(Horspool(p,s));
    return 0;
}
