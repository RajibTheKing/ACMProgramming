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



int main()
{
    long long n, m, c, kase=0;
    long long cs[30];
    bool f[30];
    while(scanf("%lld %lld %lld", &n, &m, &c)==3)
    {
        //if(kase) printf("\n");
        if(n==0&&m==0&&c==0) break;

        for(int i=0;i<n;i++)
            scanf("%lld", &cs[i]);
        for(int i=0;i<n;i++)
            f[i]=false;


        long long cur = 0;
        long long mx = -999999999, t;
        for(int i=0;i<m;i++)
        {
            scanf("%lld", &t);
            if(f[t-1]==false)
            {
                cur = cur + cs[t-1];
                if(mx<cur) mx=cur;
                f[t-1]=true;
            }
            else
            {
                cur = cur - cs[t-1];
                if(mx<cur) mx=cur;
                f[t-1]=false;
            }
        }
        printf("Sequence %lld\n", ++kase);
        if(mx<=c)
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %lld amperes.\n\n", mx);
        }
        else
            printf("Fuse was blown.\n\n");





    }


    return 0;
}

