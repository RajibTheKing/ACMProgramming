#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

#define sz 5000100
typedef long long LL;
int prime[1000000];
bool flag[sz+100];
int sieve(void)
{
    int i, j, k=-1, r;
    for(i=3;i<=sz;i+=2)
        flag[i]=true;
    flag[2]=true;
    prime[++k]=2;
    for(i=3;i<sz;i+=2)
    {
        if(flag[i])
        {
            prime[++k]=i;
            if(sz/i>=i)
            {
                r=i*2;
                for(j=i*i;j<sz;j+=r)
                    flag[j]=false;
            }
        }
    }

    return k;
}

vector<LL> fact;
vector<LL> cnt;
LL ans[100000], ptr;
bool f;

void Create_Vector(LL n, int lim)
{
    LL t = n;
    int i, kount=-1;
    for(i=0;prime[i]*prime[i]<=t&&i<=lim;i++)
    {
        if(t%prime[i]==0)
        {
            kount++;
            fact.push_back(prime[i]);
            cnt.push_back(0);
            while(t%prime[i]==0)
            {
                cnt[kount]++;
                t/=prime[i];
            }

        }
    }
    if(t>1)
    {
        kount++;
        fact.push_back(t);
        cnt.push_back(1);
    }
    //for(int i=0;i<fact.size();i++)
        //cout<<fact[i]<<" "<<cnt[i]<<endl;
}
void Compute(LL x, LL t)
{
    if(x==fact.size())
    {
        //cout<<t<<endl;
        ans[ptr++]=t;
        return;
    }
    for(int i=0;i<=cnt[x];i++)
    {
        Compute(x+1, t);
        t*=fact[x];
    }
    return;

}
int main()
{

    int lim;
    lim=sieve();
    //cout<<lim<<endl;

    LL p, l, q, t, kase=0;
    cin>>t;
    while(t--)
    {
        fact.clear();
        cnt.clear();
        memset(ans, 0, sizeof(ans));
        ptr=0;
        f=false;
        cin>>p>>l;
        Create_Vector(p-l, lim);
        Compute(0, 1);
        sort(ans, ans+ptr);

        printf("Case %lld:", ++kase);
        for(int i=0;i<ptr;i++)
            if(ans[i]>l)
            {
                f=true;
                cout<<" "<<ans[i];
            }
        if(f==false)
            cout<<" impossible";
        cout<<endl;




    }
    return 0;
}


