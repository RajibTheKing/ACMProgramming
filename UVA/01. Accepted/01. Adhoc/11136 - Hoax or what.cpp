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
int main()
{
    multiset<int> ms;
    multiset<int>::iterator it;
    int n, k, temp;
    long long res;
    while(cin>>n&&n)
    {
        res = 0;
        ms.clear();
        for(int i=0; i<n; i++)
        {
            cin>>k;
            for(int j=0;j<k;j++)
            {
                cin>>temp;
                ms.insert(temp);
            }
            it = ms.end(); it--;
            res = res + *it - *ms.begin();
            ms.erase(it);
            ms.erase(ms.begin());

        }
        cout<<res<<endl;
    }


}


