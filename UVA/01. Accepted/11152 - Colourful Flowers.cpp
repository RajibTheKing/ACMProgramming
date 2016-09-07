#include<iostream.h>
#include<math.h>
#define PI 2*acos(0)
int main()
{
    double a, b, c;
    while(scanf("%lf %lf %lf", &a, &b, &c)==3)
    {
        double area, incircle_area, excircle_area;
        double R, r, s, cosA, sinA;
        s=(a+b+c)/2;
        area=sqrt((s*(s-a)*(s-b)*(s-c)));
        r=area/s;
        R=(a*b*c)/(4*area);
        incircle_area = PI * r * r;
        excircle_area = PI * R * R;
        excircle_area=excircle_area-area;
        area=area-incircle_area;

        printf("%.4lf %.4lf %.4lf\n", excircle_area, area,  incircle_area);
    }
    return 0;
}
