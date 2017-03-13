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

#define sz 5000
int prime[1000];
bool flag[sz+100];
int D[1000];


void sieve(void)
{
    int i, j, k=-1, r;
    for(i=3;i<=sz;i+=2)
        flag[i]=true;
    prime[++k]=1;
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
        if(prime[k]>1000) break;
    }
    D[0]=0;
    D[1]=1;
    for(int i=2;i<=1000;i++)
    {
        if(flag[i])
            D[i]=D[i-1]+1;
        else
            D[i]=D[i-1];
    }

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;

}



int main()
{
    sieve();
    int N, C, Centre, Start;

    while(scanf("%d %d", &N, &C)==2)
    {
        cout<<N<<" "<<C<<":";
        //cout<<D[N]<<endl;
        if(D[N]%2)
            Centre = D[N]/2 + 1;
        else
            Centre = D[N]/2;
        Start = Centre - (C - 1);
        if(Start<1)
            Start=1;

        if(D[N]%2)
            for(int i=Start-1, j=0;j<(C*2-1) && prime[i]<=N; j++, i++)
                cout<<" "<<prime[i];
        else
            for(int i=Start-1, j=0;j<C*2&& prime[i]<=N; j++, i++)
                cout<<" "<<prime[i];
        cout<<endl<<endl;

    }


    return 0;

}

