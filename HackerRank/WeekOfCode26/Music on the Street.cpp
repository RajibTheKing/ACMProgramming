
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
#define SZ 1000010

int main()
{
    LL n, m, hmin, hmax;
    LL a[SZ];
    scanf("%lld", &n);
    int newLen = n+2;
    for(int i=2;i<newLen;i++)
    {
        scanf("%lld", &a[i]);
    }
    scanf("%lld %lld %lld", &m, &hmin, &hmax);
    a[0] = a[2] - hmax;
    a[1] = a[2] - hmin;

    LL startingPoint = a[0];

    for(int i=1;i<newLen;i++)
    {
        LL diff = a[i] - a[i-1];
        if(a[i]-startingPoint>=m)
        {
            break;
        }
        if(diff<hmin || diff > hmax)
        {
            startingPoint = a[i];
        }
    }

    printf("%lld\n", startingPoint);

    return 0;
}
