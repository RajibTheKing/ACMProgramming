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
#define csprnt printf("Case %d:", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

list<int> l;

LL MIN(LL a, LL b)
{
    if(a<b) return a;
    return b;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int P, C, temp;
    int kase=0;
    string s;
    while(cin>>P>>C)
    {
        if(P==0&&C==0) break;
        l.clear();

        temp = MIN(P, 1000);

        for(LL i=1;i<=temp;i++)
            l.push_back(i);

        csprnt;
        cout<<endl;

        for(int i=0;i<C;i++)
        {
            cin>>s;
            if(s=="N")
            {
                temp = l.front();
                cout<<temp<<endl;
                l.pop_front();
                l.push_back(temp);


            }

            if(s=="E")
            {
                cin>>temp;
                l.remove(temp);
                l.push_front(temp);

            }

        }
    }

}


