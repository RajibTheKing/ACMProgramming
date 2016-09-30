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
#include <clocale>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


map<string, int> mp;


int main()
{
    int T, N, D, val, kase=0;
    cin>>T;
    string str;
    while(T--)
    {
        mp.clear();
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>str;
            cin>>val;
            mp[str]=val;
        }
        cin>>D;
        cin>>str;
        csprnt;
        if(mp[str]==0||mp[str]>(D+5))
            cout<<"Do your own homework!"<<endl;
        else if(mp[str]<=D)
            cout<<"Yesss"<<endl;
        else
            cout<<"Late"<<endl;


    }

    return 0;
}
