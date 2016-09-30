#include<iostream>
#include<math.h>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int S[15];
int dp[15][15];

int N, M;

int rec(int cur, int last)
{
    if(cur==N) return 1;
    if(dp[cur][last]!=-1)
        return dp[cur][last];

    dp[cur][last] = 0;

    for(int i=1;i<=M;i++)
    {
        int diff = abs(last-S[i]);

        if(diff<=2)
            dp[cur][last]+=rec(cur+1, S[i]);
    }



    return dp[cur][last];


}

int main()
{
    int kase=0, T, ans;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>M>>N;
        for(int i=1;i<=M;i++)
            cin>>S[i];

        memset(dp, -1, sizeof(dp));

        for(int i=1;i<=M;i++)
            ans+=rec(1,S[i]);

        printf("Case %d: %d\n",++kase,ans);


    }

    return 0;

}
