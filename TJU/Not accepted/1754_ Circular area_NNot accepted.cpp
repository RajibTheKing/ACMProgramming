#include<iostream.h>
#include<math.h>
int main()
{
    double x1, y1, r1, x2, y2, r2, cs, c, CBD, CAD, A, B, area;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2)==6)
    {
        cs=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        c=sqrt(cs);


        if(c<r1&&r2>=2*r1)
            area=0;
        else if(c<r2&&r1>=2*r2)
            area = 0;

        else if(c>(r1+r2))
            area=0;
        else
        {
            CBD=2*(acos((r2*r2+cs-r1*r1)/(2*r2*c)));
            CAD=2*(acos((r1*r1+cs-r2*r2)/(2*r1*c)));
            A=sin(CAD);
            B=sin(CBD);
            area=(CBD*r2*r2-r2*r2*B+CAD*r1*r1-r1*r1*A)/2;
        }
        printf("%0.3lf\n", area);
    }
    return 0;
}
