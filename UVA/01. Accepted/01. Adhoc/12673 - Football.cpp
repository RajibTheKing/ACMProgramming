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

int a[100500];
int main()
{
    int N, G, S, R;
    while(scanf("%d %d", &N, &G)==2)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d %d", &S, &R);
            a[i]=R-S;
        }
        sort(&a[0], &a[N]);
//        for(int i=0;i<N;i++)
//            cout<<a[i]<<" ";
//        cout<<endl;

        int point=0;
        for(int i=0;i<N;i++)
        {
            if(a[i]<0)
            {
                point+=3;
                continue;
            }
            if(a[i]+1<=G)
            {
                point+=3;
                G=G-a[i]-1;
                continue;
            }

            if(a[i]==G)
            {
                point+=1;
                G-=a[i];
                continue;
            }
            if(a[i]==0)
            {
                point+=1;
                continue;
            }
            if(G==0&&a[i]>0) break;



        }
        printf("%d\n", point);
    }


    return 0;
}
