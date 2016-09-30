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

int a[100500];
int main()
{
    int N, R, T;
    while(scanf("%d %d", &N, &R)==2)
    {
        memset(a, 0, sizeof(a));
        for(int i=0;i<R;i++)
        {
            scanf("%d", &T);
            a[T]=1;
        }
        if(N==R)
            printf("*\n");
        else
        {
            for(int i=1;i<=N;i++)
            {
                if(a[i]==0) printf("%d ", i);
            }
            printf("\n");
        }

    }



    return 0;
}
