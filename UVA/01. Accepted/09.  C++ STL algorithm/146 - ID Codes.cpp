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

    char a[100];
    while(gets(a))
    {
        if(a[0]=='#') break;
        bool flag=false;
        while(next_permutation(a, a+strlen(a)))
        {
            puts(a);
            flag=true;
            break;

        }
        if(flag==false)
            printf("No Successor\n");
    }

    return 0;
}
