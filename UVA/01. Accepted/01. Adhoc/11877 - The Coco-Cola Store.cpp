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


map<string, int> mp;


int rec(int n)
{
    if(n<=1) return 0;
    if(n==2||n==3) return 1;
    int ret = 0;
    ret = ret + (int) n/3 + rec((int) n/3 + n%3);

    return ret;
}

int main()
{
    int n;
    while(cin>>n&&n)
    {
        cout<<rec(n)<<endl;
    }
    return 0;
}
