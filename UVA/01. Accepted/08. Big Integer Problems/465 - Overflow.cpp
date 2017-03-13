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
#define MAX 2147483647
using namespace std;




int main()
{
    long double  a, b, ans;
    char first[20000], second[20000];

    char op;
    while(scanf("%s %c %s", first, &op, second)==3)
    {
        printf("%s %c %s\n", first, op, second);
        a=atof(first);
        b=atof(second);

        if(a>MAX)
            printf("first number too big\n");
        if(b>MAX)
            printf("second number too big\n");
        if(op=='+')
        {
            ans=a+b;
            if(ans>MAX)
                printf("result too big\n");
        }
        else
        {
            ans=a*b;
            if(ans>MAX)
                printf("result too big\n");
        }



    }

    return 0;
}
