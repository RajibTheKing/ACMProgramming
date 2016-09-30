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
    int n, x, y, ans;
    while(cin>>n&&n)
    {
        x=0;y=0;
        ans = -1;
        for(y=1; pow(y+1, 3)-pow(y,3)<=n; y++)
        {
            //cout<<"Here: "<<endl;
            for(x=y+1;pow(x,3)-pow(y,3)<=n;x++)
            {
                ans = pow(x,3)-pow(y,3);
                //cout<<ans<<endl;
                if(ans==n) goto PrintAns;
            }
        }
        PrintAns:
        if(ans==n)
            cout<<x<<" "<<y<<endl;
        else
            cout<<"No solution"<<endl;


    }

    return 0;
}

