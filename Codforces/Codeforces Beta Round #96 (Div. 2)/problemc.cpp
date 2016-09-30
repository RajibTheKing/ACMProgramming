#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long LL;
#define MOD 1000003

string make_binary(int a)
{
    string r="";
    while(a)
    {
        if(a%2==0)
            r+="0";
        else
            r+="1";
        a/=2;
    }
    return r;
}

int value(string a)
{
    int t, r=0, f=1, base = 2;
    for(int i=a.length()-1;i>=0;i--)
    {
        t=a[i]-'0';


        r+=t*f;

        f*=2;
    }

    return r;
}


int main()
{
    string a, b;
    LL ans;
    char ff;
    int temp,ttt, c, d=0;
    a="";
    for(int i=0; ;i++)
    {
        scanf("%c", &ff);

        if(ff=='\n') break;
        a+=ff;

    }
    {
        ttt=0;
        b="";
        for(int i=0;i<a.length();i++)
        {
            temp=a[i];
            b=make_binary(temp);
            b+="0";
            if(b.length()!=8)
                b+="0";

            c=value(b);
            ans = (256 - (c-ttt))%256;



            ttt = c;

            cout<<ans<<endl;
        }

    }


}
