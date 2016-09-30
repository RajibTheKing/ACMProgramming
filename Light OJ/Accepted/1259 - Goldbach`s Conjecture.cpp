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

#define sz 10001000
int prime[800000];
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

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}


int main()
{
    int lim = sieve();

    int kase, temp, a, n, b, val, kount;
    cin>>kase;
    for(int i=1;i<=kase;i++)
    {
        cin>>n;
        val=n/2 + 1;
        kount = 0;
        for(int j=0;prime[j]<val;j++)
        {
            a = prime[j];
            b = n-prime[j];
            if(flag[b])
                kount++;
        }
        printf("Case %d: %d\n", i, kount);

    }

}
