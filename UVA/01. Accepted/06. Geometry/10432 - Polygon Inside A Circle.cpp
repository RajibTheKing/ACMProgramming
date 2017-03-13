#include<iostream.h>
#include<math.h>
#define PI 3.141592653589793
main()
{
    double r, n, area;
    while(scanf("%lf %lf", &r, &n)==2)
    {
        area=(r*r*n*sin(2*PI/n))/2; printf("%.3lf\n", area);
    }
}
