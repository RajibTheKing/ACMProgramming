#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
#define SZ 100000

bool flag[SZ+100];
int prime[SZ+100];

vector<int> p;
vector<int> f;

void sieve(void)
{
    int i, j, total=0, val;
    for(i=2;i<SZ;i++) flag[i]=1;
    val=sqrt(SZ)+1;
    for(i=2;i<val;i++)
    {
        if(flag[i])
        {
            for(j=i;j*i<=SZ;j++)
            {
                flag[i*j]=0;
            }
        }
    }

    for(i=2;i<=SZ;i++)
        if(flag[i])
            prime[total++]=i;

    //cout<<"last Prime: "<<prime[total-1]<<".  "<<total<<endl;
}

long long Function(long long n)
{
    int i, val, count, cnt;
    long long ans=n, temp=1, Divisors=1, value=n;
    val=sqrt(n)+1;

    for(i=0;prime[i]<val;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            Divisors=Divisors*(cnt+1);
            ans/=prime[i];
            temp*=prime[i]-1;
            val=sqrt(n)+1;
        }

    }
    if(n>1)
    {
        ans/=n;
        temp*=n-1;
        Divisors=Divisors*2;

    }
    //cout<<ans<<" "<<temp<<endl;
    ans=ans*temp;
    return value-ans-Divisors+1;
}
int main()
{
    sieve();
    long long n, ans;
    while(scanf("%lld", &n)==1)
    {


        p.clear();
        ans = Function(n);
        if(ans!=-1)
            printf("%lld\n", ans);
        else printf("0\n");
    }
}
