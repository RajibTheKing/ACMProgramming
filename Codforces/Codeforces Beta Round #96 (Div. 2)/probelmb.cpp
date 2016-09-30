#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long LL;
#define MOD 1000003

long long BigMod(long long base, long long power, long long mod)
{
    long long ans = 1;
    while(power>0)
    {
        if(power%2==1)
            ans = (ans * base) % mod;
        power/=2;
        base = (base*base) % mod;
    }
    return ans;
}

LL value(string a)
{
    LL t, r=0, f=0, base = 2;
    //cout<<a.length()<<endl;

    for(int i=a.length()-1;i>=0;i--)
    {
        t=a[i]-'0';

        r  = r + (t * BigMod(2, f, MOD));
        //cout<<r<<endl;

        f++;
    }
    //cout<<"F: "<<f<<endl;
    //cout<<r<<endl;
    r = r%MOD;
    //cout<<"r: "<<r<<endl;
    return r;
}


int main()
{
    string a, b;
    LL ans;
    while(cin>>a)
    {
        b="";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='>')
                b+="1000";
            if(a[i]=='<')
                b+="1001";
            if(a[i]=='+')
                b+="1010";
            if(a[i]=='-')
                b+="1011";
            if(a[i]=='.')
                b+="1100";
            if(a[i]==',')
                b+="1101";
            if(a[i]=='[')
                b+="1110";
            if(a[i]==']')
                b+="1111";
        }
        //cout<<b<<endl;
        ans = value(b);


        cout<<ans<<endl;
    }


}
