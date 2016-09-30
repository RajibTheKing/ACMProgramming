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
        if(prime[k]>20000) break;
    }

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

int find(long long n, int lim)
{
    int val, i, j, cnt=0, M=0;
    val = sqrt(n)+1;
    for(int i=0; prime[i]<val&&i<=lim;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            val = sqrt(n)+1;
            M = max(M, cnt);

        }
    }
    if(n>1)
    {
        M=max(M, 1);
    }
    return M;

}
int main()
{
    int lim = sieve();
    int t;
    cin>>t;
    long long n;
    while(t--)
    {
        cin>>n;
        cout<<find(n, lim)<<endl;

    }





}

