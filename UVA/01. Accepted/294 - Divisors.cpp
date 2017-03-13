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

#define sz 5000100
int prime[10000];
bool flag[sz+100];
int D[1000005];

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
        if(prime[k]>1000000) break;

    }

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;

}

LL number_of_divisors(LL n)
{
    if(n==1) return 1;

    LL s=sqrt(n)+1;

    long long sum=0;

    for(int i=0;prime[i]<=s&&i<=78498;i++)
    {
        if(n%prime[i]==0)
        {
            int kount=0;
            while(n%prime[i]==0)
            {
                kount++;
                n/=prime[i];
            }

            if(sum==0)
                sum=kount+1;
            else
                sum*=(kount+1);

            s=sqrt(n) + 1;
        }
    }

    if(n>1)
        sum= (sum==0)? 2 : (sum*2) ;
    return sum;
}

int main()
{
    sieve();
    LL kase, L, U, Max, Num, R;
    cin>>kase;
    while(kase--)
    {
        Max=0;

        cin>>L>>U;
        for(LL i=L;i<=U;i++)
        {

            R=number_of_divisors(i);
            if(R>Max)
            {
                Max=R;
                Num=i;
            }

        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, U, Num, Max);
    }


    return 0;

}

