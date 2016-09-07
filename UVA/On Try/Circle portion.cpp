#include<iostream.h>
#include<math.h>
#define pi 3.14159

main()
{
    double x1, x2, y1, y2, r1, r2;
    double A, B, t1,d, s, area1, area2, area3, ans;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2)==6)
    {
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(d>=(r1+r2))
        {
            ans=0;
            goto output;
        }


        s=d+r1+r2;
        s=s/2;
        t1=sqrt(s*(s-r1)*(s-r2)*(s-d));
        area1=t1*2;




        t1=(d*d)+(r2*r2)-(r1*r1);
        t1=t1/(2*d*r2);
        A=acos(t1);
        A=(180/pi)*A;
        area2=((pi*r2*r2)/360)*A;
        area2=area2*2;
        t1=d*d+r1*r1-r2*r2;
        t1=t1/(2*d*r1);
        B=acos(t1);
        B=(180/pi)*B;
        area3=((pi*r1*r1)/360)*B;
        area3=area3*2;
        ans=-area1+area2+area3;
output:
        if(ans>=0)
            printf("%.3lf\n",ans);
        else
        {
            ans=0;
            printf("%.3lf\n",ans);
        }
    }

}
