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

int main()
{
    int N, Q;
    string first, second;
    cin>>N;
    getchar();
    map<string,string> mp;
    mp.clear();
    while(N--)
    {

        getline(cin, first);
        getline(cin, second);
        mp[first]=second;
    }
    cin>>Q;
    getchar();
    while(Q--)
    {
        getline(cin, first);
        cout<<mp[first]<<endl;
    }



    return 0;
}

