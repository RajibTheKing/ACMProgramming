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
    int a, b, c, D, L, val, kount;
    while(cin>>a>>b>>c>>D>>L)
    {
        if(a==0&&b==0&&c==0&&D==0&&L==0) break;

        kount=0;
        for(int i=0;i<=L;i++)
        {
            val = a*i*i + b*i + c;
            if(val%D==0)
                kount++;
        }
        cout<<kount<<endl;
    }

    return 0;
}
