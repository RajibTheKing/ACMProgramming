#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.141592653589793
int main()
{
    double x1, x2, x3, y1, y2, y3;
    double as, bs, cs, cosAs, sinAs, sinA, r, ans, a;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)==6){
    as=((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3));
    bs=((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3));
    cs=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
    cosAs=((bs+cs-as)*(bs+cs-as))/(4*bs*cs);


    sinAs=1-cosAs;

    sinA=sqrt(sinAs);
    a=sqrt(as);
    r=a/(2*sinA);

    ans= 2*PI*r;
    printf("%.2lf\n", ans);
    }

    return 0;
}
