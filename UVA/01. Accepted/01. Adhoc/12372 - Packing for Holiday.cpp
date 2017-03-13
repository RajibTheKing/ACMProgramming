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

    int T, kase=0, L, W, H;
    cin>>T;
    while(T--)
    {
        cin>>L>>W>>H;
        bool flag=true;
        if(L>20||W>20||H>20)
            flag=false;
        if(flag)
            cout<<"Case "<<++kase<<": good"<<endl;
        else
            cout<<"Case "<<++kase<<": bad"<<endl;
    }

    return 0;
}

