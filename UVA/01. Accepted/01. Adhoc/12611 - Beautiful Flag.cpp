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
#define csprnt printf("Case %d:\n", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)
int main()
{
    int T, kase=0, R, W, H, R1, R2, h;
    cin>>T;
    while(T--)
    {
        cin>>R;
        csprnt;
        W = 100*R/20;
        H = 60*R/20;
        R1 = 45*W/100;
        R2 = 55*W/100;
        h = H/2;
        cout<<"-"<<R1<<" "<<h<<endl;
        cout<<R2<<" "<<h<<endl;
        cout<<R2<<" -"<<h<<endl;
        cout<<"-"<<R1<<" -"<<h<<endl;

    }




}


