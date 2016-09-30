#include<iostream>
#include<math.h>
#include<stdio.h>
#define pi 3.1415926535897932384626433832795

using namespace std;

int main()
{
    double R1, R2, R3, B, C, A, ABC, s, AB, BC, CA, ans, a, b, c;
    int n, kase=0;
    cin>>n;
    while(n--)
    {
        scanf("%lf %lf %lf", &R1, &R2, &R3);

        AB = R1 + R2;
        BC = R1 + R3;
        CA = R3 + R2;
        a  = BC; b = CA; c = AB;
        s = (AB + BC + CA)/2;
        ABC = sqrt(s*(s-a)*(s-b)*(s-c));



        A  = acos((b*b+c*c-a*a)/(2*b*c));
        B  = acos((a*a+c*c-b*b)/(2*a*c));
        C  = acos((b*b+a*a-c*c)/(2*b*a));


        ans = ABC - (R1*R1*B + R2*R2*A + R3*R3*C)*0.5;

        printf("Case %d: %lf\n", ++kase, ans);

    }

    return 0;
}
