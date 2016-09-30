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


int main()
{
    LL T, kase = 0;
    LL ans, n;
    LL a[4];
    LL p[4];
    string s, t;
    char c1, c2, c3;
    cin>>T;
    while(T--)
    {
        cin>>a[0]>>c1>>a[1]>>c2>>a[2]>>c3>>a[3];
        s="";
        cin>>s;
        int h=-1;
        int j, k;
        for(int i=0;i<s.length();i+=9)
        {
            t="";
            for(j=i,k=0; k<8; k++, j++)
            {
                t+=s[j];

            }
            p[++h]=value(t);
        }
        bool flag=true;
        for(int i=0;i<4;i++)
        {
            if(p[i]!=a[i])
            {
                flag = false;
                break;
            }
        }

        if(flag==true)
            printf("Case %lld: Yes\n", ++kase);
        else
            printf("Case %lld: No\n", ++kase);

    }

    return 0;
}
