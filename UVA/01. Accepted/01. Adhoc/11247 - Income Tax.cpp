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
    long long m, x, ans;
    double aa, mm, xx, temp;
    while(cin>>m>>x)
    {
        if(m==0&&x==0) break;

        if(x==100||x==0) { cout<<"Not found"<<endl; continue;}
        mm=m;
        xx=x;

        aa = (mm-1)*100.0/(100.0-xx);
        temp = floor(aa);

        if(aa - temp > 1e-10)
            aa=temp;
        else
            aa=temp-1;

        if(aa>=m)
            printf("%0.0lf\n", aa);
        else
            cout<<"Not found"<<endl;
    }


    return 0;
}
