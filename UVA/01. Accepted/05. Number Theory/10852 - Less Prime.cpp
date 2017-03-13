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

#define sz 100010
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
    }

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

int main()
{
    int lim = sieve();
    int t, n, d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        d=n/2;
        for(int i=0;;i++)
        {
            if(prime[i]>d)
            {
                cout<<prime[i]<<endl;
                break;
            }
        }

    }



}
