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
    double a, b, c, s, r;

    while(cin>>a>>b>>c)
    {
        if(a*b*c==0)
            printf("The radius of the round table is: 0.000\n");
        else
        {
            s = (a+b+c)/2;
            r = sqrt(s*(s-a)*(s-b)*(s-c)) / s;
            printf("The radius of the round table is: %0.3lf\n", r);
        }

    }

    return 0;
}

