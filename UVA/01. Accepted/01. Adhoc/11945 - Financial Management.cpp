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


int main()
{
    double sum,avg, val;
    int T, kase=0;
    setlocale(LC_ALL, "en_US.UTF-8");

    cin>>T;
    while(T--)
    {
        sum=0;
        for(int i=0;i<12;i++)
        {
            cin>>val;
            sum+=val;
        }

        printf("%d $%'.2lf\n", ++kase, sum/12.0);
    }


    return 0;
}
