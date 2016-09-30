#include<iostream>

#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>
//#define pi 3.1415926535897932384626433832795
#define pi 2*acos(0)
using namespace std;


main()
{
    double theta, r1, r2, r3, h, h1, h2, p,t, ans;
    int test;
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        cin>>r1>>r2>>h>>p;
        theta = atan((r1-r2)/h);
        t= p*tan(theta);

        h1 = r2 / tan(theta);
        h2 = h1+p;

        r3 = r2+t;

        ans = (1.0/3.0) * pi * r3*r3 * h2 -  (1.0/3.0) * pi * r2*r2 * h1;

        printf("Case %d: %lf\n",i, ans);




    }

}

