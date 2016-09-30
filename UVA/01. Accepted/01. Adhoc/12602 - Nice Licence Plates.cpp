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

int main()
{
    char c1, c2, c3;
    int k;
    int T, sum1, sum2, n1, n2, n3;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        c1=getchar();
        c2=getchar();
        c3=getchar(); getchar();
        scanf("%d", &k); getchar();
        sum1=0;sum2=0;
        n1 = c1-'A';
        n2 = c2-'A';
        n3 = c3-'A';
        sum1 = n1*26*26 + n2*26 + n3*1;
        sum2 = k;
        //cout<<n1<<" "<<n2<<" "<<n3<<endl;
        //cout<<sum1<<" "<<sum2<<endl;
        if(abs(sum1-sum2)<=100)
            cout<<"nice"<<endl;
        else
            cout<<"not nice"<<endl;


    }

    return 0;
}
