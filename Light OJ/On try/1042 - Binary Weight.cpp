#include<iostream>
#include<string>
#include<string.h>
using namespace std;
typedef long long LL;

LL value(string a)
{
    LL t, r=0, f=1;
    for(int i=a.length()-1;i>=0;i--)
    {
        t=a[i]-'0';
        r+=t*f;
        f=f*2;
    }
    //cout<<r<<endl;

    return r;
}

LL calculate(LL n)
{
    string b, a;
    LL k, i, j, temp, res;
    k=n;
    b="";
    while(k)
    {
        if(k%2==0)
            b+="0";
        else
            b+="1";
        k/=2;

    }

    a="";
    for(i=b.length()-1;i>=0;i--)
        a+=b[i];

   // cout<<a<<endl;

    for(i= a.length()-1;i>=0;i--)
        if(a[i]=='1') break;
    temp = i;

    bool flag=false;
    for(i=temp-1;i>=0;i--)
    {
        if(a[i]=='0')
        {
            a[i]='1';
            a[temp]='0';
            flag=true;
            break;
        }
    }

    if(flag==true)
    {
        res = value(a);
        return res;
    }
    else
    {
        int h=0;

        for(i=0;i<a.length();i++)
            if(a[i]=='1')
                h++;
        a+='0';
        if(h==1)
        {
            res=value(a);
            return res;
        }

        //cout<<a<<endl;
        for(i=1;i<a.length();i++)
            a[i]='0';
        //cout<<h<<endl;
       i=a.length();
       for(j=1;j<h;j++)
            a[--i]='1';

        //cout<<a<<endl;

        res=value(a);

        return res;

    }


}
int main()
{
    LL T, kase = 0;
    LL ans, n;

    cin>>T;
    while(T--)
    {
        cin>>n;
        ans = calculate(n);

        printf("Case %lld: %lld\n", ++kase, ans);

    }

    return 0;
}
