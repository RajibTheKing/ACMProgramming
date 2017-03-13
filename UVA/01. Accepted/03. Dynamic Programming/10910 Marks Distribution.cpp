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

int N, P, T;
int dp[100][100];

int rec(int cur, int temp)
{
    if(temp>T) return 0;
    if(cur==N-1&&temp==T)
        return 1;
    if(cur==N) return 0;

    int &ret = dp[cur][temp];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0;i<=T;i++)
    {
        ret+=rec(cur+1, temp+P+i);
    }
    return ret;
}

int main()
{
    int t, ans;

    cin>>t;
    while(t--)
    {
        cin>>N>>T>>P;
        ans=0;
        memset(dp, -1, sizeof(dp));
        for(int i=P;i<=T;i++)
        {
            ans+=rec(0, i);
        }
        cout<<ans<<endl;
    }
}

