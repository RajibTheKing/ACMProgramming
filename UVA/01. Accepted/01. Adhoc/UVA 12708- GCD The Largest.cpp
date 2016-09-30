#include<stdio.h>
main()
{
    int t;
    long long N;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%lld", &N);
        printf("%lld\n", N/2);
    }
}
