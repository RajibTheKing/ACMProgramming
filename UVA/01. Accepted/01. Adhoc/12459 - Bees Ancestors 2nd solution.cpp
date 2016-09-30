#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)



long long dp[100];

long long rec(int n)
{
    if(n<=1) return 1;
    long long &ret = dp[n];
    if(ret!=-1) return ret;

    return ret = rec(n-1)+rec(n-2);
}
int main()
{

    memset(dp, -1, sizeof(dp));
    int n, kount=0;
    while(scanf("%d", &n))
    {
        if(n==0) break;
        printf("%lld\n", rec(n));
    }

    return 0;
}
