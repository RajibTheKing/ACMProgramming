#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
#define s 60004

int dp[s], a[105], n, sum, i, j, t, ans;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof(dp));

        scanf("%d", &n);
        sum=0;
        for(i=0; i<n;i++)
        {
            scanf("%d", &a[i]);
            sum=sum+a[i];
        }
        dp[0]=1;
        for(i=0; i<n; i++)
        {
            for(j=sum; j>=0; j--)
            {
                if(dp[j]==1)
                    dp[j+a[i]]=1;
            }
        }
        ans=1<<30;

        for(j=sum; j>=0; j--)
        {
            if(dp[j]==1)
            {
                i=abs(j-(sum-j));
                if(i<ans)
                    ans=i;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
