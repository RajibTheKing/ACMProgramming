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


int main()
{
    int T, temp, n, m;
    scanf("%d", &T);
    map<int, int> kount;
    map<int, int>::iterator it;

    while(T--)
    {
        scanf("%d %d", &n, &m);
        kount.clear();
        for(int i=0;i<n;i++){ scanf("%d", &temp); kount[temp]++;}
        for(int i=0;i<m;i++){ scanf("%d", &temp); kount[temp]--;}
        int sum = 0;
        for(it = kount.begin();it!=kount.end();it++){ sum = sum + abs((*it).second);}
        printf("%d\n", sum);

    }

    return 0;
}
