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
#define INF 999999999
using namespace std;
int main()
{
    int street[600];
    int Test, r, minimum, sum;
    scanf("%d", &Test);
    getchar();

    while(Test--)
    {
        scanf("%d", &r);
        for(int i=0;i<r;i++)
            scanf("%d", &street[i]);
        sort(street, street+r);
        minimum=INF;
        for(int i=0;i<r;i++)
        {
            sum=0;
            for(int j=0;j<r;j++)
                sum+=abs(street[i]-street[j]);
            minimum=min(sum, minimum);

        }
        printf("%d\n", minimum);
        memset(street, 0, sizeof(street));
    }

    return 0;
}
