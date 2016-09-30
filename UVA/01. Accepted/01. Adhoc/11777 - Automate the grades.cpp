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
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

char Grade(int n)
{
    if(n>=90) return 'A';
    if(n>=80&&n<90) return 'B';
    if(n>=70&&n<80) return 'C';
    if(n>=60&&n<70) return 'D';
    if(n<60) return 'F';
}

int main()
{
    int a[4];
    int T, term1, term2, fn, att, kase=0;
    cin>>T;
    while(T--)
    {
        cin>>term1>>term2>>fn>>att>>a[0]>>a[1]>>a[2];
        sort(a, a+3);
        int mark = term1+term2+fn+att+(a[2]+a[1])/2;
        csprnt;
        cout<<Grade(mark)<<endl;
    }

    return 0;
}
