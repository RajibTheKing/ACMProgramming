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
#define sz 100000
bool flag[sz+100];
int prime[50000];

void sieve()
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
    //cout<<prime[k]<<" "<<k<<endl;



}
void calculate(int n)
{
    printf(" %d =", n);

    int ans, i,x, j, k, factor;
    bool cc=false;
    for(i=0;prime[i]<=n;i++)
    {
        x=n;
        factor=0;
        while(x>1)
        {
            x/=prime[i];
            factor+=x;
        }
        if(cc==false)
        {
            printf(" %d (%d)", prime[i], factor);
            cc=true;
        }
        else
            printf(" * %d (%d)", prime[i], factor);
    }
    cout<<endl;
    return;
}

int main( )
{
    sieve();
    int t, n, kase=0;
    cin>>t;
    while(t--)
    {
        cin>>n;

        printf("Case %d:", ++kase);

        calculate(n);
    }


    return 0;
}

