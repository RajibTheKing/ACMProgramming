#include <stdio.h>
int num[1000006];

long long rec(long long n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;

    return rec(n/2 ) + n%2;
}
int main()
{
    long long i,n,cas;
    scanf("%lld",&cas);
    while(cas--)
    {
        scanf("%lld",&n);
        printf("%lld\n",rec(n));
    }
    return 0;
}
