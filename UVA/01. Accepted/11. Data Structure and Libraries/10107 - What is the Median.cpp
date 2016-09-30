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
    unsigned int a[20000];
    int t, i=0, h, x;
    while(scanf("%d", &t)==1)
    {
        a[i++]=t;
        sort(a, a+i);
        if(i%2==1)
        {
            h=i/2;
            printf("%d\n",a[h]);

        }
        else
        {
            h=i/2;
            x=(a[h]+a[h-1])/2;
            printf("%d\n", x);
        }

    }

    return 0;
}

