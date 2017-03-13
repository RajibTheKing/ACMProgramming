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
#include <clocale>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


map<int, bool> mp;

int main()
{
    int n, m, val, kount;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        mp.clear();
        kount=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &val);
            mp[val]=true;

        }
        for(int i=0;i<m;i++)
        {
            scanf("%d", &val);
            if(mp[val]==true)
                kount++;
        }
        cout<<kount<<endl;
    }
}
