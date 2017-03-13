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

typedef struct Node
{
    int val;
    int cnt;
};

Node coin[100];


long long dp[5000];
int main()
{
    int t, n, k, c, sum;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>coin[i].val;
        for(int i=0;i<n;i++)
            cin>>coin[i].cnt;
        memset(dp, 0, sizeof(dp));

        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=k;j>=0;j--)
            {
                if(dp[j])
                {
                    for(int p=1;p<=coin[i].cnt;p++)
                    {
                        if(j+coin[i].val*p>k) break;
                        dp[j+coin[i].val*p]=dp[j+coin[i].val*p] + dp[j];
                        dp[j+coin[i].val*p] =  dp[j+coin[i].val*p]%100000007;
                    }
                }
            }
        }

        printf("Case %d: %lld\n", kase, dp[k]);


    }
}
