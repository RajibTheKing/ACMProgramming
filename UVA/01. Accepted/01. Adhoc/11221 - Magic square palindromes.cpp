#include<iostream>
#include<map>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<vector>

using namespace std;

string clearString(string s)
{
    string t="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' '||s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!'||s[i]=='('||s[i]==')'||s[i]=='{'||s[i]=='}'||s[i]=='['||s[i]==']')
            continue;
        t+=s[i];
    }
    return t;
}
bool Check(string s)
{
    int len=s.size();
    int r = sqrt(len), c=sqrt(len), k=-1;
    string board[1000];
    vector<string> prev;
    prev.clear();
    for(int i=0;i<r;i++)
    {
        board[i]="";
        for(int j=0;j<c;j++)
        {
            board[i]+=s[++k];
        }
    }

    for(int i=0;i<r;i++)
    {
        string t1="", t2="";
        for(int j=i;j<r;j++)
        {
            t1+=board[i][j];
        }
        prev.push_back(t1);
        for(int j=i;j<r;j++)
        {
            t2+=board[j][i];
        }
        if(t1!=t2)
            return false;
    }
    k=-1;
    for(int i=r-1;i>=0;i--)
    {
        string t1="", t2="";
        for(int j=i;j>=0;j--)
        {
            t1+=board[i][j];
        }
        for(int j=i;j>=0;j--)
        {
            t2+=board[j][i];
        }
        if(t1!=prev[++k]) return false;
        if(t2!=t1) return false;

    }
    return true;
}
main()
{
    map<int, bool> M;
    M.clear();
    for(int i=1;i*i<=10000;i++)
        M[i*i]=true;
    int T, len;
    bool flag;
    cin>>T;
    getchar();
    string s;
    for(int k=1;k<=T;k++)
    {
        getline(cin, s);
        s = clearString(s);
        len=s.size();
        if(M[len]==false)
            flag=false;
        else
            flag=Check(s);

        cout<<"Case #"<<k<<":"<<endl;
        int ans=sqrt(len);
        if(flag)
            cout<<ans<<endl;
        else
            cout<<"No magic :("<<endl;
    }


}
