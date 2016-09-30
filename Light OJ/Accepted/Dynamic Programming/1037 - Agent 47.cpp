#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 99999999
int a[30], n;
string m[30];
int dp[1<<16];

int rec(int msk)
{
    if(msk==0) return 0;
    int &ret = dp[msk];
    if(ret!=-1) return ret;
    ret = INF;

    for(int i=0;i<n;i++)
    {
        int bit = msk & (1<<i);
        if(bit!=0)
        {
//            msk &= ~(1<<i);
            for(int j=0;j<n;j++)
            {
                int b = msk&(1<<j);
                if(b==0)
                {
                    int p = m[j][i]-'0';
                    if(p==0) p=1;
                    int shot;
                    if(a[i]%p==0) shot = a[i]/p;
                    else shot = a[i]/p + 1;
//                    cout<<"Cur = "<<i<<", Power = "<<p<<", Shot = "<<shot<<endl;
                    ret = min(ret, shot+rec(msk^(1<<i)) );
                }
            }
//            msk |= 1<<i;

        }

    }
    return ret;
}

int main()
{
    int T, kase=0, ans, msk;
    cin>>T;

    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>m[i];
        memset(dp, -1, sizeof(dp));
        ans=INF;
        msk = (1<<n) - 1;
        //cout<<msk<<endl;
        for(int j=0;j<n;j++)
        {
//            msk &= ~(1<<j);
            ans = min(ans, a[j]+rec(msk^(1<<j)));
//            msk |= 1<<j;
        }

        printf("Case %d: %d\n", ++kase, ans);

    }
}
