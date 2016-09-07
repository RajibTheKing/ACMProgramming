#include<stdio.h>
main()
{
     long n,k,i,d;
     while(2==scanf("%ld %ld",&n,&k))
     {
        d=n/k;
        i=n%k;
        n+=d;
        d+=i;
        while(d>=k)
        {
            i=d%k;
            d=d/k;
            n+=d;
            d+=i;
        }
        printf("%ld\n",n);
     }
}
