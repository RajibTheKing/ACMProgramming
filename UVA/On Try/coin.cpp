#include<iostream.h>
#include<string.h>
#include<math.h>
int dp[1000000];
int a[1000000];

int main()
{

    int n;
    int i, j,sum, min, t;
    cin>>t;

    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        cin>>n;
        sum=0;
        dp[0]=1;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        for(i=0; i<n; i++)
        {
            for(j=sum ; j>=0; j--)
            {
                if(dp[j]==1)
                {
                    dp[j+a[i]]=1;
                }
            }
        }

        for(i=sum/2; i<=sum; i++)
        {
            if(dp[i]!=0)
            {
                min=abs(i-sum);
                break;
            }
        }

        min=abs(min-i);

        printf("%d\n", min);
    }

    return 0;
}
