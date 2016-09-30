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


int board[20][20];
LL sum[20];
int main()
{
    int n, part, kase=0;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &board[i][j]);
        part = ceil(n/2.0);
        for(int i=0;i<part;i++)
            sum[i]=0;
        int indx;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                indx = min(i, j);
                indx =  min(indx, n-i-1);
                indx = min(indx, n-j-1);
                sum[indx]+=board[i][j];
                //cout<<indx<<" = "<<Grid1[i][j]<<endl;
            }
        }


        csprnt;
        for(int i=0;i<part;i++)
        {
            if(i) cout<<" ";
            cout<<sum[i];
        }
        cout<<endl;




        //cout<<part<<endl;





    }


    return 0;
}

