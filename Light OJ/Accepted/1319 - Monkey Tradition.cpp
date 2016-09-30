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

long long Extended_Euclidean(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }

    long long d;

    d=Extended_Euclidean(b,a%b,y,x);
    y=y-(a/b)*x;

    return d;

}

long long Inverse_MOD(long long a,long long m)
{
    long long x,y,d;

    d=Extended_Euclidean(a,m,x,y);

    if(d==1)
        return (x+m)%m;
    return -1;
}


int main()
{
    int a[100], n[100], B;
    LL t, N, k, sum;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        start:
        cin>>k;
        N=1;
        sum=0;
        for(int i=0;i<k;i++)
        {
            cin>>n[i]>>a[i];
            N*=n[i];

        }

        for(int i=0;i<k;i++)
        {
            B = Inverse_MOD(N/n[i], n[i]);
            if(B==-1)
            {
                printf("Case %d: Impossible\n", kase);
                kase++;
                goto start;
            }

            sum = sum + a[i]*B*(N/n[i]);
        }

        printf("Case %d: %lld\n", kase, sum%N);


    }
    return 0;
}
