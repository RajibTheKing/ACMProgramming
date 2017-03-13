#include<iostream>
#include<cmath>
#include<math.h>
#include<stdio.h>
#define pi 2*acos(0)
using namespace std;

int main()
{
    double A, B, C, D, a, t;
    double x, y, z;
    while(cin>>a)
    {
        t=pi*a*a/6.0 - sqrt(3.0)*a*a/4;

        A = 1.0*pi*a*a/4.0;
        B = ( sqrt(3.0)*a*a/4.0 ) + 2*t;

        y = 3.0*A - a*a - 2.0*B;

        z= 2.0*A - a*a - 2.0*y;

        x=  B- 2.0*y -z;

        printf("%.3lf %.3lf %.3lf\n",z,4*y,4*x);

    }
    return 0;
}
