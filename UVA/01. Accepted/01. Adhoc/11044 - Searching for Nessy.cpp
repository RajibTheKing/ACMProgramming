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
    double n, m;

    while(Test--)
    {
        cin>>n>>m;


        printf("%d\n", (int) (n/3) * (int) (m/3));

    }

    return 0;
}

