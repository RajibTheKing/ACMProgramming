
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
    vector<int>v;
//    for(int i=10;i<100;i+=5) v.pb(i);
    v.pb(2);
    v.pb(10);
    v.pb(10);
    v.pb(10);
    v.pb(100);

    vector<int>::iterator it=lower_bound(v.begin(),v.end(),10);
    int indx=it-v.begin();

    it=upper_bound(v.begin(),v.end(),10);
    int indx2=it-v.begin();

    cout<<indx<<" "<<indx2<<endl;
    return 0;
}
