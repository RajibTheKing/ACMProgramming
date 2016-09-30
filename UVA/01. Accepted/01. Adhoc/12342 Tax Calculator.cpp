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

double Min(double a, double b)
{
    if(a<b) return a;
    return b;
}
int main()
{

    LL T, kase=0, tax;
    double total, a;
    cin>>T;
    while(T--)
    {
        cin>>a;
        csprnt;

        tax=1;
        if(a<=180000)
            tax=0;
        else
        {

            total=0;
            a-=180000;
            total = total + (double) Min(a,300000)*0.1;
            a-=300000;
            if(a>0)
                total=total + (double) Min(a,400000)*0.15;

            a-=400000;
            if(a>0)
                total=total + (double) Min(a,300000)*0.2;
            a-=300000;
            if(a>0)
                total=total + (double) a*0.25;
        }
        total=ceil(total);

        if(tax==0)
            tax=0;
        else if(total<2000)
            tax=2000;
        else
            tax = (long long) total;
        cout<<tax<<endl;



    }

    return 0;
}

