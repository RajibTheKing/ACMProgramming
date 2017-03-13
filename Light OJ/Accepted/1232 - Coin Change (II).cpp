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

Node coin[505];


long long dp[50000];
int main()
{
    int t, n, k, c, sum;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>coin[i].val;

        memset(dp, 0, sizeof(dp));

        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            c=coin[i].val;

            for(int j=0;j<=k;j++)
            {
                if(dp[j])
                {
                    if(j+c>k) break;
                    dp[j+c]=dp[j+c]+dp[j];
                    dp[j+c]=dp[j+c]%100000007;
                }
            }
        }

        printf("Case %d: %lld\n", kase, dp[k]);


    }
}
