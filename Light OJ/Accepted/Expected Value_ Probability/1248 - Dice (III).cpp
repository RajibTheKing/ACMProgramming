#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
double dp[100900];
int N;
double rec(int k)
{
    if(k==0) return 0;
    if(dp[k]>-1) return dp[k];
    dp[k] = (double) N/ (double) k + rec(k-1);
    return dp[k];
}

int main()
{
    int Test, kase=0;
    cin>>Test;
    while(Test--)
    {
        memset(dp, -1, sizeof(dp));
        cin>>N;
        printf("Case %d: %.10lf\n",++kase,rec(N));
    }
    return 0;
}

