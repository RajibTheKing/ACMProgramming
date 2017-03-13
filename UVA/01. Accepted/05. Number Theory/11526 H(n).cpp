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
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

int main()
{
    LL T, n, k, ans, prev, next;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);
         if ( n < 1 ) {
            printf ("0\n");
            continue;
        }
        k=(LL) sqrt(n);
        ans=0;
        prev=n;
        for(int i=1;i<=k;i++)
        {
            next = n/i;
            ans+=next;
            ans+=(prev-next)*(i-1);
            prev=next;
        }
        if(prev>k)
            ans+=k;

        printf("%lld\n", ans);

    }

    return 0;
}

