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


int a[11];


int main()
{
    int T;
    cin>>T;
    cout<<"Lumberjacks:"<<endl;
    while(T--)
    {
        for(int i=0;i<10;i++)
            cin>>a[i];
        bool flag=true;
        for(int i=1;i<10;i++)
        {
            if(a[i]<a[i-1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"Ordered"<<endl;
            continue;
        }

        flag=true;
        for(int i=8;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"Ordered"<<endl;
            continue;
        }
        cout<<"Unordered"<<endl;

    }

    return 0;
}
