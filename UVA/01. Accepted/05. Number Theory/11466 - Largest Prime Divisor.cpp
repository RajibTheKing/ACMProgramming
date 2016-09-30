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
LL N, Max, t, val;
int main()
{
    int lim = sieve();
    int f;

    while(cin>>N)
    {
        if(N==0) break;
        if(N<0) N*=-1;

        Max = 0;
        f=0;
        t=N;
        val = sqrt(t)+1;
        for(int i=0;prime[i]<val&&i<=lim;i++)
        {
            if(t%prime[i]==0)
            {
                f++;
                if(Max<prime[i])
                    Max=prime[i];
                while(t%prime[i]==0)
                {
                    t/=prime[i];
                }
                val = sqrt(t)+1;

            }
        }
        if(t>1)
        {
            f++;
            if(Max<t)
                Max=t;
        }
        //cout<<"Answer is........: ";
        if(f>=2)
            cout<<Max<<endl;
        else
            cout<<"-1"<<endl;


    }


}
