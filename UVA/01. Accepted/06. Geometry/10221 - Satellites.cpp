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
    string unit;
    double s, a;
    double Arc_dis, Chor_dis;

    while(cin>>s>>a>>unit)
    {
        if(unit=="min")
            a = 1.0*a/60;
        if(a>180)
            a=360-a;

        s = s+6440;
        Arc_dis = 2*pi*s*a/360;
        a = a*pi/180;

        Chor_dis = sqrt(s*s + s*s - 2*s*s*cos(a));
        printf("%0.6lf %0.6lf\n", Arc_dis, Chor_dis);
    }

    return 0;
}

