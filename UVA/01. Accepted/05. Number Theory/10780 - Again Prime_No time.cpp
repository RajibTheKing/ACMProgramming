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
    int factor;
    int cnt;
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
Node R1[10001], R2[10001];

int Create_For_M(int M, int lim)
{
    int i, j, kount, val, t=M, k=-1;
    val = sqrt(t)+1;

    for(i=0;prime[i]<val&&i<=lim;i++)
    {
        if(t%prime[i]==0)
        {
            R1[++k].factor=prime[i];
            R1[k].cnt=0;

            while(t%prime[i]==0)
            {
                R1[k].cnt++;
                t/=prime[i];
            }
            val = sqrt(t) + 1;
        }
    }
    if(t>1)
    {
        R1[++k].factor=t;
        R1[k].cnt=1;
    }
//    for(i=0;i<=k;i++)         cout<<R1[i].factor<<" "<<R1[i].cnt<<endl;

    return k;
}
int Create_For_N(int N, int lim)
{
    int i, j, k=-1, t=N;
    for(i=0;prime[i]<=N;i++)
    {
        t=N;
        R2[++k].factor=prime[i];
        R2[k].cnt=0;
        while(t>0)
        {
            R2[k].cnt += t/prime[i];
            t/=prime[i];
        }

    }
    //for(i=0;i<=k;i++)         cout<<R2[i].factor<<" "<<R2[i].cnt<<endl;

    return k;
}
bool Is_M_Divides_N(int M, int N, int k1, int k2)
{
    bool p, f = true;
    for(int i=0;i<=k1;i++)
    {
        p=false;
        for(int j=0;j<=k2;j++)
        {

            if(R1[i].factor==R2[j].factor)
            {
                p=true;
                if(R1[i].cnt>R2[j].cnt)
                {
                    f=false;
                    break;
                }
            }
        }
        if(!p)
        {
            f=false;
            break;
        }

        if(!f) break;
    }
    return f;
}


int main()
{
    int lim = sieve();
    //cout<<__gcd(8,2)<<endl;
    int kase=0, M, N, test, k1, k2, t;
    bool flag;
    cin>>test;
    while(test--)
    {
        cin>>M>>N;
        printf("Case %d:\n", ++kase);
        memset(R1, 0, sizeof(R1));
        memset(R2, 0, sizeof(R2));

        k1 = Create_For_M(M, lim);
        k2 = Create_For_N(N, lim);

        flag = Is_M_Divides_N(M, N, k1, k2);
        int min=99999999;

        if(flag)
        {
            for(int i=0;i<=k1;i++)
            {
                for(int j=0;j<=k2;j++)
                {
                    if(R1[i].factor==R2[j].factor)
                    {
                        t = R2[j].cnt/R1[i].cnt;
                        if(min>t) min = t;
                    }

                }
            }
            cout<<min<<endl;
        }
        else
        cout<<"Impossible to divide"<<endl;



    }


}

