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

#define sz 10100
int prime[800];
bool flag[sz+100];

typedef struct Node
{
    int mu;
    int M;
};

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
Node Result[1000001];
bool f;
int Factorize_For_N(int M, int lim)
{
    int i, j, kount, val, t=M, cnt;
    val = sqrt(t)+1;
    kount=0;
    for(i=0;prime[i]<val&&i<=lim;i++)
    {

        if(t%prime[i]==0)
        {
            cnt=0;

            while(t%prime[i]==0)
            {
                kount++;
                cnt++;
                t/=prime[i];
            }

            if(cnt>=2) f=true;

            val = sqrt(t) + 1;
        }
    }
    if(t>1)
    {
        kount++;
        if(f==false)
            f=false;

    }
//    for(i=0;i<=k;i++)         cout<<R1[i].factor<<" "<<R1[i].cnt<<endl;

    return kount;
}




int main()
{
    int lim = sieve();
    int temp;
    Result[1].mu = 1;
    Result[1].M = 1;

    for(int i=2;i<=1000000;i++)
    {
        f=false;
        temp=Factorize_For_N(i, lim);
        if(f)
            Result[i].mu = 0;
        else if(temp%2)
            Result[i].mu = -1;
        else
            Result[i].mu = 1;
        Result[i].M = Result[i-1].M + Result[i].mu;
        //cout<<Result[i].M<<endl;


    }
    //for(int i=1;i<=20;i++)
       // cout<<i<<" "<<Result[i].mu<<" "<<Result[i].M<<endl;

    int N, k;
    while(cin>>N)
    {
        if(N==0) break;
        k = Factorize_For_N(N, lim);
        printf("%8d%8d%8d\n", N, Result[N].mu, Result[N].M);


    }


}


