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

#define sz 101000
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
int R[8000001];


void Create_For_N(int N, int lim)
{
    int i, j, kount, t=N, val;
    val = sqrt(t)+1;
    kount=0;
    for(i=0;prime[i]<val&&i<=lim;i++)
    {

        if(t%prime[i]==0)
        {
            while(t%prime[i]==0)
            {
                kount++;
                t/=prime[i];
            }
            val = sqrt(t) + 1;

        }


    }
    if(t>1)
    {
        kount++;

    }
    R[N]=R[N-1]+kount;

    return;
}


int func(int n)
{
    int ans = 0;
    for(int i=0;;i++)
    {
        if(R[i]<=n)
            ans++;
        else
            return ans;
    }

}
int main()
{
    int i, lim = sieve();
    R[0]=1;
    R[1]=1;
    R[2]=1;
    for(i = 3;; i++)
    {
        Create_For_N(i, lim);

        //cout<<"For: "<<i<<"! ="<<R[i]<<endl;
        if(R[i]>10000000) break;

    }
    //cout<<R[i]<<" "<<i<<endl;
    //cout<<"Complete"<<endl;
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<func(n)<<endl;

    }


}

