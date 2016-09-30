#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define Max ((1<<16) + 1)

int dp[17][Max];
int A[17][17];
int n;

int rec(int cur, int mask)
{
    int j;

    if(cur>=n) return 0;
    //cout<<"rajib"<<endl;

    int &ret = dp[cur][mask];
    if(ret!=-1) return ret;

    //cout<<"rajib"<<endl;

    ret = 0;

    for(j=0;j<n;j++)
        if((mask &(1<<j)) == 0)
            ret = max(ret,  A[cur][j] + rec(cur+1, mask|(1<<j)));

    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d", &A[i][j]);

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %d\n", kase, rec(0, 0));
    }
    return 0;
}

