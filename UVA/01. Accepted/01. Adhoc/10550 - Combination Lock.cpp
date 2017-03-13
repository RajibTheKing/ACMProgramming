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



int ClockWise(int p, int q)
{
    int m = min(p, q);
    p = p - m;
    q = q - m;

    if(p<=q) return q*9;

    else return (360 - ClockWise(q, p));

}

int Counter_ClockWise(int p, int q)
{
    int ret = 360-ClockWise(p, q);
    return ret;
}

int main()
{
    int start, a, b, c;

    while(cin>>start>>a>>b>>c)
    {
        if(start==0&&a==0&&b==0&&c==0) break;
        int ans = 1080;

        ans = ans + Counter_ClockWise(start, a);
        ans = ans + ClockWise(a, b);
        ans = ans + Counter_ClockWise(b, c);

        cout<<ans<<endl;

    }

    return 0;
}

