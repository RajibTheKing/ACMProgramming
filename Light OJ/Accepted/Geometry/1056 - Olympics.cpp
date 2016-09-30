#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;




int main()
{
    int Test, kase=0;
    scanf("%d", &Test);
    getchar();
    char c;
    double a, b, C, A, B, p, x, SinC, SinB;
    while(Test--)
    {
        scanf("%lf %c %lf", &a,&c,&b);
        C = atan(b/a);

        SinC = sin(C);
        SinB = sin(pi/2);

        C = C*180/pi*1.0;
        B = 90;
        A = 180-B-C;
        p = 180-A-A;
        //cout<<A<<" "<<B<<" "<<C<<endl;
        //cout<<SinC<<endl;
        x = ( 200*360*SinC ) / ( 360*a*SinC + pi*p*b*SinB);
        printf("Case %d: %lf %lf\n", ++kase, a*x*1.0, b*x*1.0);
    }

    return 0;
}
