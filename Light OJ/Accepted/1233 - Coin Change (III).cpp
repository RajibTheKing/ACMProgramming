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

Node coin[105];

bool comp(Node a, Node b)
{
    if(a.val*a.cnt<b.val*b.cnt) return true;

    return false;
}
long long dp[900005];
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

        sort(&coin[0], &coin[n], comp);


        dp[0]=1;
        long long sum=0, kount=0;
        for(int i=0;i<n;i++)
        {
            sum+=coin[i].val*coin[i].cnt;

            c = coin[i].val;

            for(int j=0;j<=sum;j++)
            {
                if(j+c>sum) break;
                if(j+c>k) break;
                if(dp[j])
                {
                    if(dp[j+c]==0) kount++;
                    dp[j+c]=1;
                }
            }
        }





        printf("Case %d: %lld\n", kase, kount);


    }
}
