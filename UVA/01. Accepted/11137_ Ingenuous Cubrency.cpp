#include<stdio.h>
int coin [25];
long long  dp[100000];


int main()
{

    int i, j, k;
    int count = 0;

    for(i=1; i<=21; i++)
    {
      coin[count]=i*i*i;
      count++;
    }

    dp[0]=1;


    for(i=0; i<21; i++)
    {
        for(j=0; j< 10009;j++ )
        {
            if(dp[j])
            dp[j+coin[i]]+=dp[j];

        }
    }
    int n;

    while(scanf("%d", &n)==1)

        printf("%lld\n", dp[n]);

    return 0;
}
