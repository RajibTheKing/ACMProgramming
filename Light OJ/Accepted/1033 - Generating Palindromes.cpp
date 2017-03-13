//1033 - Generating Palindromes
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


string str;
int dp[205][205];

int rec(int first, int last)
{
    if(first>last) return 0;
    // for(int i=0;i<str.length();i++)
        //for(int j=0;j<str.length();j++)
            //cout<<dp[i][j]<<" ";
        //cout<<endl;

    int &ret = dp[first][last];
    if(ret!=-1) return ret;

    if(str[first]==str[last])
        ret=rec(first+1, last-1);
    else
    {
        ret = 1 + rec(first+1, last);
        ret = min(ret, 1 + rec(first, last-1));
    }

    return ret;
}

int main()
{

    int t;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {
        cin>>str;

        memset(dp, -1, sizeof(dp));
        int ans = rec(0, str.length()-1);

        printf("Case %d: %d\n", kase, ans);
    }

    return 0;
}

