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



void Ternary(long long N)
{
    if(N==0) return;
    else
    {

        Ternary(N/3);
        printf("%d", N%3);
    }
    return;
}

int main()
{
    int Test, kase=0;
    long long N;

    while(cin>>N)
    {
        if(N<0) break;

        if(N==0)
            printf("0");
        else
            Ternary(N);
        cout<<endl;

    }

    return 0;
}

