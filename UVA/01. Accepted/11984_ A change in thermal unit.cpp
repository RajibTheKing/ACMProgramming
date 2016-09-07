#include<stdio.h>
main()
{
    double C , F, D, increase;
    int t, kase=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf", &C, &D);
        F=(9*C)/5+32;
        F=F+D;
        C=((F-32)/9)*5;

        printf("Case %d: %.2lf\n", ++kase, C);
    }
}
