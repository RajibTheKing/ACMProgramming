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

#define sz 1000

char s[1005];
int dp[sz][sz];

int rec(int i, int j)
{
    if(i>j) return 0;
    int &ret = dp[i][j];
    if(ret!=-1) return ret;

    if(s[i]==s[j])
    {
        if(i==j)
            ret = 1 + rec(i+1, j-1);
        else
            ret = 2 + rec(i+1, j-1);
    }
    else
    {
        ret = max(rec(i+1, j), rec(i, j-1));
    }
    return ret;
}


int main()
{
    int t;
    char c;
    scanf("%d", &t);
    scanf("%c", &c);

    while(t--)
    {
        gets(s);
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, strlen(s)-1);
        printf("%d\n", ans);
    }
    return 0;
}
