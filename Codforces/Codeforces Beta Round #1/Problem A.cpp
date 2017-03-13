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
using namespace std;

#define pi 3.1415926535897932384626433832795


int main()
{
    double n, m, a;
    long long ans;
    cin>>n>>m>>a;

    printf("%0.0lf\n", ceil(n/a)*ceil(m/a));

    return 0;
}
