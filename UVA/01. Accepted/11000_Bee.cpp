#include<iostream.h>
main()
{
    while(1)
    {
        long long n, i;
        scanf("%lld", &n);
        if(n<0)
            break;
        long long f=1, m=0, total=1, m1, m2, male=0;
        for(i=1; i<=n; i++)
        {
            m1=f;
            m2=m;
            f=m;
            m=m1+m2;
            male=male+m;
            total=total+m+f;
        }
        printf("%lld %lld\n", male, total);
    }
}
