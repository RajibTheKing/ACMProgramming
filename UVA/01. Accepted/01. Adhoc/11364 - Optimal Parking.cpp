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

int a[25];

int main()
{
    int T, n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];

        int minimum = (1<<20);
        int maximum = -(1<<20);
        for(int i=0;i<n;i++)
        {
            minimum = min(minimum, a[i]);
            maximum = max(maximum, a[i]);
        }
        cout<<(maximum-minimum)*2<<endl;

    }

    return 0;
}

