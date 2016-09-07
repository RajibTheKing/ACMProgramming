#include<iostream.h>
long long dp[1000000];


long long fibonacci(long long n)
{

    long long &ans=dp[n];

    if(dp[n]!=0) return ans;

    if(n<=2)
    {
        return 1;

    }
    else
    {
        ans=fibonacci(n-1)+fibonacci(n-2);

        return ans;
    }
}

main()
{
    long long n;
    long long ans;
    ans=fibonacci(5000);

    while(scanf("%lld", &n)==1)
    {
        ans=fibonacci(n);
        printf("The Fibonacci number for %lld is %lld\n", n, ans);


    }
}
