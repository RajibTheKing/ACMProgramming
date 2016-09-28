#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

bool IsProbable(string s1, string s2)
{
    if(s1.size()!=s2.size()) return false;

    int cnt = 0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }
    if(cnt>1) return false;

    return true;

}
int main()
{
    int t, n, kase = 0;
    cin>>t;
    string str[1001];
    string dadsNum;

    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }
        cin>>dadsNum;
        printf("Case %d:\n", ++kase);
        for(int i=0;i<n;i++)
        {
            if(IsProbable(str[i], dadsNum))
                cout<<str[i]<<endl;
        }
    }
}
