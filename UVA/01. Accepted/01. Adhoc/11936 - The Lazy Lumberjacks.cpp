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
    while(T--)
    {
        for(int i=0;i<3;i++)
            cin>>a[i];
        sort(a, a+3);
        if(a[2]>=a[0]+a[1])
            cout<<"Wrong!!"<<endl;
        else
            cout<<"OK"<<endl;


    }

    return 0;
}
