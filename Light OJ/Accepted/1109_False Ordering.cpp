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

#define sz  1000
typedef struct node
{
    int a;
    int b;
};

node ans[1010];

bool flag[sz+100];
int prime[1000];
void sieve()
{
    int i, j, k;
    k=-1;
    prime[++k]=2;
    for(i=3;i<sz;i+=2)
    {
        if(flag[i]==false)
        {
            prime[++k]=i;
            for(j=i+i;j<sz;j+=i)
                flag[j]=true;
        }
    }
    //for(int l=0;l<167;l++)
      //  cout<<prime[l]<<" "<<l<<endl;
}
bool comp(node p, node q)
{
    if(p.b==q.b)
    {
        if(p.a>q.a)
            return true;
        else return false;


    }

    if(p.b>q.b)
        return false;
    else
        return true;



}
void calculate(void)
{
    int temp, d, k, f;
    for(int n=1;n<=1000;n++)
    {
        temp=n;
        d=1;
        k=0;
        f=0;
        while(temp>1)
        {
            if(temp%prime[k]==0)
            {
                temp=temp/prime[k];
                f++;
            }
            else
            {
                d=d*(f+1);
                f=0;
                k++;
            }
        }
        d = d*(f+1);

        ans[n].a=n;
        ans[n].b=d;


    }

    sort(&ans[1], &ans[1001], comp);
}

int main()
{
    //freopen("false_ordering.txt", "w", stdout);
    sieve();
    calculate();
    int t, n, kase=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("Case %d: %d\n", ++kase, ans[n].a);
    }

    return 0;
}
