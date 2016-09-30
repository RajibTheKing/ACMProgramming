#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>
#include<algorithm>

using namespace std;

int board[101][101], n, m;
bool flag[101][101];
int dp[500001];
int t;


main()
{
    int test, i, j, l;
    int a[101];

    cin>>test;
    for(l=1;l<=test; l++)
    {
        dp[0]=1;
        int n;
        cin>>n;
        int sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        for(i=0;i<n;i++)
        {
            for(j=sum;j>=0;j--)
            {
                if(dp[j])
                {
                    //dp[j+a[i]]+=dp[j];
                    dp[j+a[i]]+=a[j];
                }
            }
        }

        int flag=0;
        cout<<dp[sum]<<endl;

        for(i=(sum/2)+1;i>=0;i--)
        {
            if(dp[i]==2)
            {
                printf("Case %d: %d\n", l,i);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("Case %d: impossible\n",l);

        memset(dp, 0, sizeof(dp));

    }

}


