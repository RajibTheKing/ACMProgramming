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
int prime[1000000];
bool flag[sz+100];

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
    //cout<<"complete"<<endl;

}




int number_of_divisors(int n)
{
    if(n==1) return 1;

    int s=sqrt(n)+1;

    long long sum=0;

    for(int i=0;prime[i]<=s;i++)
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


int sum[1000000];
int main()
{
    sieve();

    int t1, t2;
    for(int i=1;i<=1000000;i++)
    {
        if( i% number_of_divisors(i) ==0)
            sum[i]++;

        sum[i]+=sum[i-1];
    }

    while(cin>>t1>>t2)
    {
        cout<<sum[t2]-sum[t1-1]<<endl;

    }
}
