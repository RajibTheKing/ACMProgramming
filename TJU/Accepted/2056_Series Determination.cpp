#include<stdio.h>
main()
{
    double a, b, c, f0, f1, f2, f3, f4, f5;
    while(scanf("%lf%lf%lf", &f0, &f1, &f2)==3)
    {
        c=f0;
        f1=f1-c;
        f2=f2-c;
        a=(f2-f1*2)/2;
        b=f1-a;
        f3=a*3*3+b*3+c;
        f4=a*4*4+b*4+c;
        f5=a*5*5+b*5+c;
        printf("%d %d %d\n", int(f3), int(f4), int(f5));

    }
}
