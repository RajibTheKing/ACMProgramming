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
typedef long long LL;

#define sz 700000
int prime[80000];
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
        if(prime[k]>70000) break;
    }

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

LL Find_Result(LL x, int lim)
{
    LL t=x, kount=0, val, ans=-1;
    val = sqrt(x) + 1;

    for(int i=0;prime[i]<val&&i<=lim;i++)
    {
        if(t%prime[i]==0)
        {
            kount=0;
            while(t%prime[i]==0)
            {
                kount++;
                t/=prime[i];
            }
            if(ans==-1) ans = kount;
            else
                ans = __gcd(ans, kount);
        }
    }
    if(t>1)
    {
        ans=1;
    }
    return ans;
}
int main()
{
    int lim = sieve();
    int kase=0, t;
    LL x, p, temp;

    cin>>t;
    while(t--)
    {
        cin>>x;
        temp=abs(x);

        p = Find_Result(temp, lim);
        if(x<0)
            while(p%2==0) p/=2;

        printf("Case %d: %lld\n", ++kase, p);
    }




}

