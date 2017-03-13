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
#define MAX 1000000000
#define LL long long
#define INF (1LL<<55)


vector<long long> Square;
vector<long long> Raw;
vector<long long> ans;
int main()
{
    long long k=1;
    while(k*k<=MAX)
    {
        Square.pb(k*k);
        Raw.pb(k);
        k++;
    }
//    cout<<Square.size()<<endl;
//    cout<<Square[Square.size()-1]<<endl;
//    cout<<k<<endl;
//    cout<<k*k<<endl;


    int T,kase=0, sz = Square.size();
    long long N, X;
    cin>>T;
    while(T--)
    {
        cin>>N;
        ans.clear();
        for(int i=0;i<sz;i++)
        {
            X = N - Square[i];
            if(X<0) break;

            if(X%Raw[i]==0&&X)
            {
                //cout<<"Here: "<<X<<endl;
                ans.pb(X);
            }

        }
        csprnt;
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;

    }





    return 0;
}

