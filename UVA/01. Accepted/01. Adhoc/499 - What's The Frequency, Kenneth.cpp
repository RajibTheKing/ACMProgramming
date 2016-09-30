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


int ans[200];


int main()
{
    char s[10000];
    //freopen("test.txt", "r", stdin);

    while(gets(s))
    {
        int len = strlen(s);
        memset(ans, 0, sizeof(ans));
        int Max = 0;
        for(int i=0;i<len;i++)
        {
            char c = s[i];
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            {
                int temp = s[i];
                ans[temp]++;
                if(Max<ans[temp])
                    Max = ans[temp];
            }
        }
        for(int i=65;i<=125;i++)
        {
            char c = i;
            if(ans[i]==Max)
                printf("%c", i);
        }
        printf(" %d\n", Max);


    }

    return 0;
}

