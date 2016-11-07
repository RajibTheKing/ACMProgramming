#include<bits/stdc++.h>

using namespace std;

long long b, d , s, mn, mx;

long long ret(long long a, long long b, long long c)
{
    long long ans = 0;
    ans+=mx-a;
    ans+=mx-b;
    ans+=mx-c;

    if(mx - c > 0)
    {
        ans--;
        if(mx-b>0)
        {
            ans--;
            if(mx-a>0)
                ans--;
        }

    }

    return ans;

}
int main()
{
    while(cin>>b>>d>>s)
    {
        mn = min(s,min(b,d));
        b-=mn; d-=mn; s-=mn;
        mx = max(s, max(b,d));

        mn = min( ret(s,b,d), min(ret(b,d,s), ret(d,s,b)));
        cout<<mn<<endl;
    }

    return 0;
}


