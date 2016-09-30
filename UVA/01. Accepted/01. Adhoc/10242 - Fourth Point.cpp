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

double X[5];
double Y[5];

bool isEqual(double x1, double y1, double x2, double y2)
{
    if(x1==x2&&y1==y2) return true;
    return false;
}
void MakePoint(double x3,double y3, double x1,double y1, double x2, double y2)
{
   // cout<<x3<<" "<<y3<<",  "<<x1<<" "<<y1<<", "<<x2<<" "<<y2<<endl;
    printf("%0.3lf %0.3lf\n", x3+x2-x1, y3+y2-y1);
}
int main()
{
    double x1, x2, x3, x4, y1, y2, y3, y4;
    bool flag;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
    {
        if(isEqual(x1,y1,x3,y3)||isEqual(x1,y1,x4,y4))
        {
            flag=true;
        }
        if(isEqual(x2,y2,x3,y3)||isEqual(x2,y2,x4,y4))
        {
            flag=false;
        }

        if(isEqual(x1,y1,x3,y3))
        {
            x3=x4;
            y3=y4;
        }
        if(isEqual(x2,y2,x3,y3))
        {
            x3=x4;
            y3=y4;
        }
       // cout<<flag<<endl;
        if(flag)
            MakePoint(x3,y3,x1,y1,x2,y2);
        else
            MakePoint(x3,y3,x2,y2,x1,y1);






    }


    return 0;
}
