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
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

int lx, ly;
vector<int> x, y;
int dp[21][21][1<<16];

int diff(int a, int b)
{
    if(a>b) return a-b;
    else return b-a;
}

int rec(int row, int column, int msk)
{
//    for(int i=0;i<x.size();i++)
//        if(msk&(1<<i))
//            cout<<"1";
//        else
//            cout<<"0";
//    cout<<endl;
    if(__builtin_popcount(msk)==x.size()) return max(diff(lx,row), diff(ly,column));
    int &ret = dp[row][column][msk];
    if(ret!=-1) return ret;
    ret = 1<<29;
    int dist;
    for(int i=0;i<x.size();i++)
    {
        if(!(msk&(1<<i)))
        {
            dist = max(diff(x[i],row), diff(y[i],column));
           // cout<<"distance: "<<dist<<endl;
            ret = min(ret, dist+rec(x[i], y[i], (msk^(1<<i)) ));
        }
    }

    return ret;
}

int main()
{
    int n, m, L, mask, ans, dist;
    string str;
    //freopen("test.txt", "r", stdin);

    while(scanf("%d %d", &n, &m)==2)
    {
        getchar();
        x.clear();
        y.clear();
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++)
        {
            cin>>str;
            for(int j=0;j<str.size();j++)
            {
                if(str[j]=='#')
                    x.pb(i),y.pb(j);
                if(str[j]=='L')
                    lx=i,ly=j;

            }
        }

//        for(int i=0;i<x.size();i++)
//            cout<<x[i]<<", "<<y[i]<<endl;
//        cout<<endl;

        L = x.size();

        ans = 1<<29;
        ans=rec(lx,ly,0);

//        for(int i=0;i<L;i++)
//        {
//            dist = max(diff(lx,x[i]), diff(ly,y[i]));
//            mask=0;
//            //cout<<"from here"<<endl;
//           // cout<<"DIstance: "<<dist<<endl;
//            ans = min(ans, dist+rec(x[i],y[i],(mask^(1<<i))));
//            //cout<<"Here: "<<ans<<endl;
//        }
        cout<<ans<<endl;

    }

    return 0;
}

