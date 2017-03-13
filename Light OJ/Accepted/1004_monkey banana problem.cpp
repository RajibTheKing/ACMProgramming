#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int board[210][110];
int dp[210][110];
int k, temp;
int bottom(void);
int main()
{
    int t, kase=0;
    cin>>t;
    int i, j, n, ans;

    while(t--)
    {
        memset(dp, -1, sizeof(board));
        cin>>n;
        k=n;
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
                scanf("%d", &board[i][j]);

        temp = 2*n-1;

        for(i=n;i<temp;i++)
            for(j=0;j<temp-i;j++)
                scanf("%d", &board[i][j]);




        ans = bottom();

        printf("Case %d: %d\n", ++kase,ans);
    }

}

int bottom(void)
{
    //cout<<"rajib"<<endl;
    dp[0][0]=board[0][0];
    int i, j;
    for(i=0;i<k-1;i++)
    {
        for(j=0;j<k;j++)
        {
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]+board[i+1][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+board[i+1][j+1]);
        }
    }
    for(i=k-1;i<temp;i++)
    {
        for(j=0;j<k;j++)
        {
            if(j-1>=0)
                dp[i+1][j-1] =max(dp[i+1][j-1], dp[i][j]+board[i+1][j-1]);
            dp[i+1][j]=max(dp[i+1][j], dp[i][j] + board[i+1][j]);
        }
    }

    return dp[temp-1][0];

}
