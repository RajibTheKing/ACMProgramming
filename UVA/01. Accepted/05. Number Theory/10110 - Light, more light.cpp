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

#define sz 500010
int prime[100000];
bool flag[sz+100];
long long a, b;

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

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

int create_vector(int lim)
{
    long long t = a, kount=0;
    long long val  = sqrt(t) + 1;
    int ret=1;
    for(int i=0; prime[i]<val;i++)
    {
        if(t%prime[i]==0)
        {

            kount=0;
            while(t%prime[i]==0)
            {
                kount++;
                t/=prime[i];
            }
            ret = ret*(kount+1);
            val = sqrt(t)+1;

        }
    }
    if(t>1)
    {
        ret=ret*2;
    }
    return ret ;
}

int main()
{
    int lim = sieve();
    long long i, kount, result;
    while(cin>>a)
    {
        if(a==0) break;
        result = create_vector(lim);
        if(result%2==1)
            printf("yes\n");
        else
            printf("no\n");

    }

    return 0;

}

