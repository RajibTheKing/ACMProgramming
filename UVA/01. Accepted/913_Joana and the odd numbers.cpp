#include<stdio.h>

main()
{
    long long last_num, a=3, p, d=2, N, s, n;
    while(scanf("%lld", &N)==1)
    {
        p=N;

        n=(p-a)/d+1;

        s=n*(a+(n-1));

        last_num=1+s*2;

        printf("%lld\n", (last_num-2)*3);
    }

}
