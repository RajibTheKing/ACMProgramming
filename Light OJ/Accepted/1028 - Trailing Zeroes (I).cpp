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

#define sz 1000100
int prime[800000];
bool flag[sz+100];
long long a, b;
vector<LL> fact;
vector<LL> cnt;

void sieve(void)
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

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return;

}

void create_vector(void)
{
    long long t = a, kount=-1;
    for(LL i=0; prime[i]*prime[i]<=t+1&&i<=78503; i++)
    {
        if(t%prime[i]==0)
        {
            fact.push_back(prime[i]);
            cnt.push_back(0);
            kount++;
            while(t%prime[i]==0)
            {
                cnt[kount]++;
                t/=prime[i];
            }
        }
    }
    if(t>1)
    {

        fact.push_back(t);
        cnt.push_back(0);
        kount++;
        cnt[kount]++;
    }
    cnt.push_back(0);
    return ;

}
LL generate_divisors(LL x, LL t)
{
    if(x==fact.size())
    {
        //printf("%10lld : is Divisor of %lld\n", t, a);
        return 1;
    }
    LL ret = 0;
    for(int i=0;i<=cnt[x];i++)
    {
        ret += generate_divisors(x+1, t);
        t   *= fact[x];
    }

    return ret;
}
int main()
{
    sieve();
    long long i, kount, result;
    int kase;
    cin>>kase;
    for(i=1;i<=kase;i++)
    {
        cin>>a;
        if(a==1)
        {
            printf("Case %lld: 0\n", i);
            continue;
        }
        create_vector();
        result = generate_divisors(0, 1);

        printf("Case %lld: %lld\n", i, result-1);
        fact.clear();
        cnt.clear();
    }
    return 0;

}

