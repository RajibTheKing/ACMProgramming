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
int dp[1005][1005];
string s;

int rec(int i, int j)
{
    if(i>j) return 0;
    int &ret = dp[i][j];
    if(ret!=-1) return ret;
    ret = 999999;
    if(s[i]==s[j])
        ret = rec(i+1, j-1);
    else
    {
        ret = min(ret, 1+rec(i+1, j));
        ret = min(ret, 1+rec(i, j-1));
        ret = min(ret, 1+rec(i+1, j-1));

    }
    return ret;

}
int main()
{
   freopen("test.txt", "r", stdin);


    int n;
    cin>>n;
    int kase=0;
    while(n--)
    {
        cin>>s;
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, s.length()-1);
        printf("Case %d: %d\n", ++kase, ans);
    }

    return 0;
}

