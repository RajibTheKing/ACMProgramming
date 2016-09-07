#include<stdio.h>
double ans[13][60];

main()
{
    int i, j;
    double t;
    t=0;

    for(i=0;i<=12;i++)
    {
        for(j=0;j<=59;j++)
        {
            if(t<=180)
                ans[i][j]=t;
            else
                ans[i][j]=360-t;

            t=(t+5.5);
            if(t>360) t=t-360;

        }

    }

    int h, m;
    char c;
    while(1)
    {
        scanf("%d%c%d", &h, &c, &m);
        if(h==0&&m==0)
            break;
        printf("%.3lf\n", ans[h][m]);
    }
}
