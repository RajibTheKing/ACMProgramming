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



long long dp[5][100], ans;

long long rec(int k, int depth)
{
    if(depth==0)
    {
        if(k==1) return 1;
        else return 0;
    }

    long long &ret=dp[k][depth];
    if(ret!=-1) return ret;
    ret = 0;
    if(k==1)
        ret = ret + 1 + rec(2, depth-1);
    else
    {
        ret =  ret + rec(2, depth-1);
        ret =  ret + rec(1, depth-1);
    }
    return ret;

}
int main()
{
   int n, kount=0;

    while(cin>>n)
    {
        if(n==0) break;
        memset(dp, -1, sizeof(dp));

        ans = rec(1, n);
        cout<<ans<<endl;

    }

    return 0;
}
