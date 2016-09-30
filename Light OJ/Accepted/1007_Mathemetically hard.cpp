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
#define sz 5000100

int prime[1000000];
bool flag[sz+1000];
unsigned long long ans[5000100];

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

void Euler_phi()
{
    unsigned long long i,x,j,f,t;

    ans[1]=1;
    for(i=2;i<sz;i++)
    {
        if(flag[i])
            ans[i]=i-1;
        else
        {
            x=i;
            for(j=0;prime[j]<i;j++)
            {
                if(x%prime[j]==0)
                {
                    f=0;
                    t=1;
                    while(x%prime[j]==0)
                    {
                        x/=prime[j];
                        f++;
                        t*=prime[j];
                    }
                    t/=prime[j];
                    ans[i]=ans[x]*t*(prime[j]-1);
                    break;
                }
            }
        }
    }
}





int main()
{

    sieve();
    Euler_phi();
    for(int i=2;i<sz;i++)
        ans[i]=ans[i-1]+ans[i]*ans[i];

    //cout<<"completed....."<<endl;


    int t, kase=0;
    int a, b, temp;
    cin>>t;

    long long sum;
    while(t--)
    {
        cin>>a>>b;

        printf("Case %d: %llu\n", ++kase, ans[b]-ans[a-1]);
    }


    return 0;
}
