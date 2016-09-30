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


int main()
{
    int a, b, c;
    int val[4];
    while(cin>>a>>b>>c)
    {
        if(a==0&&b==0&&c==0) break;
        val[0]=a; val[1]=b; val[2]=c;
        sort(val, val+3);
        if(val[0]*val[0] + val[1]*val[1] == val[2]*val[2])
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;



    }
}
