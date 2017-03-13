
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
int prime[1000000];
bool flag[sz+100];

vector<LL> fact;
vector<LL> cnt;
LL Div[2000], ptr;

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

}

void create_vector(LL n)
{
    long long t = n, kount=-1;
    for(LL i=0; prime[i]*prime[i]<=t+1&&i<100000; i++)
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


//    for(int i=0;i<fact.size();i++)
//    {
//        cout<<fact[i]<<"= "<<cnt[i]<<endl;
//    }
    //cout<<endl;
    return ;

}
LL generate_divisors(LL x, LL t)
{
    if(x==fact.size())
    {
        //printf("%10lld : is Divisor of %lld\n", t, a);
        Div[ptr++]=t;
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
bool Check(LL a, LL b, LL c, LL L)
{
    long long t1, t2;
    t1 = (a*b)/__gcd(a, b);
    t2 = (t1*c)/__gcd(t1, c);
    //cout<<"In check: "<<t2<<endl;
    if(t2==L)
        return true;

    return false;
}
int main()
{
    sieve();
    int kase=0, t;
    long long i, a, b, c, L, result;

    cin>>t;
    while(t--)
    {
        cin>>a>>b>>L;

        if(L%a!=0||L%b!=0)
        {
            printf("Case %d: impossible\n", ++kase);
            continue;

        }
        ptr=0;
        create_vector(L);
        result = generate_divisors(0, 1);
        //cout<<result<<endl;
        //cout<<"Total Divisors found: "<<result<<endl;
        sort(Div, Div+ptr);
        //for(i=0;i<ptr;i++)
            //cout<<Div[i]<<endl;

        for(i=0;i<ptr;i++)
        {
            if(L%Div[i]==0)
            {
                //cout<<"in if: "<<Div[i]<<endl;
                if(Check(a, b, Div[i], L))
                {
                    printf("Case %d: %lld\n", ++kase, Div[i]);
                    goto end;
                }
            }
        }

        end:

        memset(Div, 0, sizeof(Div));
        fact.clear();
        cnt.clear();
    }
    return 0;

}
