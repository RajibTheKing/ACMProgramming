//10469 - To Carry or not to Carry
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

string tobinary(long long t)
{
    string s="";
    char c;

    while(t>0)
    {
        c=t%2+'0';
        s+=c;
        t/=2;
    }
    return s;
}
long long ToDecimal(string t)
{
    int d=1, n;
    long long sum=0;
    for(int i=0;i<t.size();i++)
    {
        n=t[i]-'0';
        sum+=d*n;

        d=d<<1;
    }
    return sum;
}
int main()
{
    string p, q, ans;
    long long a, b, temp, res;
    char t1, t2;
    while(cin>>a>>b)
    {
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        p=tobinary(a);
        q=tobinary(b);
        ans="";
        for(int i=0;i<p.size();i++)
        {
            t1=p[i];
            if(i>=q.size())
                t2='0';
            else
                t2=q[i];
            if(t1!=t2)
                ans+="1";
            else ans+="0";

        }
        res=ToDecimal(ans);
        cout<<res<<endl;

    }
}
