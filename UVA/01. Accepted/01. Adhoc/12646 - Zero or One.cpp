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
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c)==3)
    {
        if(a==b&&b==c) cout<<"*"<<endl;
        if(a==b&&b!=c) cout<<"C"<<endl;
        if(b==c&&b!=a) cout<<"A"<<endl;
        if(a==c&&c!=b) cout<<"B"<<endl;
    }

    return 0;
}
