#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
main()
{
    double R, r, n, A;
    int kase=0, t;
    cin>>t;
    while(t--)
    {
        cin>>R;
        cin>>n;

        A=3.141592653589793238/n;
        r=R*sin(A)/(1+sin(A));

        printf("Scenario #%d:\n", ++kase);
        printf("%0.3lf\n\n", r);
    }
}
