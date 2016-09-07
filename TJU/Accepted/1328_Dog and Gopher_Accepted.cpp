#include<stdio.h>
#include<iostream.h>
#include<math.h>
int main()
{
    while(1)
    {
        double x1, x2, y1, y2, d1=0, d2=0;
        double x, y, a, b;
        int flag;
        scanf("%lf %lf %lf %lf", &x1,  &y1, &x2, &y2);

        flag=1;
        while(scanf("%lf %lf", &x, &y)==2)
        {

            d1=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
            d2=sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y));

            if(d2>=(d1*2))
            {
                flag=0;
                a=x;
                b=y;


            }


        }

        if(flag==0)
            {
                printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", a, b);
                goto end;
            }
        else
            {
                printf("The gopher cannot escape.\n");
                goto end;
            }


    }
    end:
    return 0;
}
