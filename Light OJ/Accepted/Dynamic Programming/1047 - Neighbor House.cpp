#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 1<<30
int C[20][3];
int dp[10][30];
int n;

int rec(int color, int mask)
{
    if(mask==0) return 0;
    int nextHouse;
    for(int i=0;i<n;i++)
    {
        if(mask & (1<<i))
        {
            nextHouse = i;
            break;
        }
    }

    int &ret = dp[color][nextHouse];
    if(ret!=-1) return ret;
    ret = INF;
    for(int i=0;i<3;i++)
    {
        if(i!=color)
        {
            ret=min(ret, C[nextHouse][i]+rec(i, mask^(1<<nextHouse)));
        }
    }
    return ret;

}
int main()
{
    int T, kase=0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d %d %d", &C[i][0], &C[i][1], &C[i][2]);
        memset(dp, -1, sizeof(dp));
        int mask = (1<<n)-1;
        int ans=INF;
        for(int i=0;i<3;i++)
        {
            ans = min(ans, C[0][i]+rec(i, mask^1));
        }
        printf("Case %d: %d\n", ++kase, ans);

    }
}
