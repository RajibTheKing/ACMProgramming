#include<iostream>
#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<math.h>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define sz 100010
bool flag[sz];long long prime[80000],k=0,sum1,sum2;
void seive()
{
    long long i,j,r,p;
    for(i=3;i<=sz;i+=2)flag[i]=1;
    flag[2]=1;
    prime[k++]=2;
    p=sz;
    for(i=3;i<p;i+=2)
    {
        if(flag[i])
        {
            prime[k++]=i;
            if(sz/i>=i)
            {
                r=i*2;
                for(j=i*i;j<p;j++)flag[i]=0;
            }
        }

    }

}
void fac(long long n)
{
    long long i,cnt,sq=sqrt(n)+1;
    sum1=1;sum2=1;
    for(i=0;prime[i]<sq;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            sq=sqrt(n)+1;
            sum1=sum1*((pow(prime[i],cnt+1)-1)/(prime[i]-1));
            sum2*=(cnt+1);
        }

    }
    if(n>1)
    {
        sum1=sum1*((pow(n,2)-1)/(n-1));
        sum2*=2;
    }

}
int main()
{
    long long t,a,b,k,i,ans1,ans2;
    seive();
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        ans1=0;ans2=0;
        for(i=a;i<=b;i++)
        {
            if(i%k==0)
            {
                fac(i);
                ans1+=sum1;
                ans2+=sum2;

            }
        }
        cout<<ans2<<" "<<ans1<<endl;
    }
}
