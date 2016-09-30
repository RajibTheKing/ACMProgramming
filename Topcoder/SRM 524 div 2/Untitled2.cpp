#include<iostream>
#include<stdio.h>
using namespace std;
int mm, N;
int dp[205][205][205];
void rec(int n1, int n2, int n3)
{
    if(dp[n1][n2][n3]==0) return;
    dp[n1][n2][n3]=0;

    if(n1*n2*n3==N)
    {
        if(mm>(n1+n2+n3))
            mm =  n1+n2+n3;
    }

    if(n1==N||n2==N||n3==N) return;




    if(dp[n1+1][n2][n3]==-1)
        rec(n1+1, n2, n3);

    if(dp[n1][n2+1][n3]==-1)
        rec(n1, n2+1, n3);
    if(dp[n1][n2][n3+1]==-1)
        rec(n1, n2, n3+1);
}
int main()
{
    memset(dp, -1, sizeof(dp));

    N = 1;

    mm = 999999;
    rec(1,1,1);

    printf("%d\n", mm);
}
