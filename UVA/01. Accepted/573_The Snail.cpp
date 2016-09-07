#include<stdio.h>
main()
{
    double h, u, d, f, c;
    int day;
    while(1)
    {
        scanf("%lf %lf %lf %lf", &h, &u, &d, &f);
        if(h==0) break;

        day=0;
        c=0;
        f=(f*u*1.0)/100;

        for(; ;)
        {
            c=c+u;
            if(c>h)
            {
                day++;
                break;
            }
            c=c-d;
            if(c<0)
            {
                day++;
                break;
            }

            u=u-f;
            if(u<0) u=0;
            day++;

        }
        if(c<=0)
            printf("failure on day %d\n", day);
        if(c>=h)
            printf("success on day %d\n", day);
    }
}
