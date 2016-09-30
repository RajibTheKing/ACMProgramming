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

LL w[1010], c[1010];
LL ability[1010];
int n;

void PreCalculate(void)
{
    int ptr=0;
    for(int i=0;i<n;i++)
    {
        for(ptr;ptr<n;ptr++)
        {
            if(c[i]<w[ptr])
                break;

        }
        ability[i]=ptr;
    }
}
int main()
{
    int T, kase=0;

    scanf("%d", &T);
    while(T--)
    {
        memset(ability, -1, sizeof(ability));
        scanf("%d", &n);
        for(int i=0;i<n;i++)
            scanf("%lld", &w[i]);
        for(int i=0;i<n;i++)
            scanf("%lld", &c[i]);
        sort(&w[0],&w[n]);
        sort(&c[0],&c[n]);
        PreCalculate();
//        for(int i=0;i<n;i++)
//            cout<<ability[i]<<", ";
//        cout<<endl;
        LL ans=1;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                ans*=ability[i];
            else
                ans*=(ability[i]-i);


            ans%=1000000007;
        }
        ans%=1000000007;
        printf("Case %d: %lld\n", ++kase, ans);
    }


    return 0;
}

