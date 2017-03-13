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

int a[55];

int main()
{
    int n, x, y;
    while(scanf("%d", &n)==1&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d", &a[i]);
        y = (n*(n-1))/2;
        x=0;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)if(__gcd(a[i], a[j])==1) x++;
        if(x==0)
            printf("No estimate for this data set.\n");
        else
            printf("%0.6lf\n", sqrt(6.0*y/x*1.0));

    }


    return 0;
}
