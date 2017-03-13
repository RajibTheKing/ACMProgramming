#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define sz 50001
int prime[1000000];
bool flag[sz+1000];
int sieve()
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
    return k;
}

bool isPrime(int n, int maxPrimeIndx)
{
    int len = sqrt(n) + 1;
    for(int k=0; k<=maxPrimeIndx&&prime[k]<=len; k++)
    {
        if(n%prime[k]==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int maxPrimeIndx =  sieve();

    int n, m, i, j;
    while(cin>>n>>m){
    if(n==1) n++;
    if(n%2==0) n++;
    int cnt = 0;
    for(i=n;i<=m;i+=2)
    {
        bool flag = true;
        flag = isPrime(i, maxPrimeIndx);

        if(flag)
        {
            j = i+2;
            if(j<=m)
            {
                flag = isPrime(j, maxPrimeIndx);
                if(flag)
                {
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<endl;
    }
    return 0;
}
