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
#define INF 999999999
using namespace std;

vector<long long>  p;

long long m[15][15], s[15][15];
long long n;

void Matrix_Chain_Order(void)
{
    long long i, l, j, k, q;
    for( i = 1; i <= n; i++ )
		m[i][i] = 0 ;


    for(l=2;l<=n;l++)
    {
        for(i=1;i<=(n-l+1);i++)
        {
            j=i+l-1;
            m[i][j]=INF;
            for(k=i;k<=(j-1);k++)
            {
                q=m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

}
void Print(long long  i, long long j)
{
    if(i==j)
        printf("A%lld", i);
    else
    {
        printf("(");
        Print(i, s[i][j]);
        printf(" x ");
        Print(s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    long long  t1, t2, kase = 0;
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
           cin>>t1>>t2;

           if(i==0)
           {
               p.push_back(t1);
               p.push_back(t2);
           }
           else
                p.push_back(t2);
        }
        Matrix_Chain_Order();
        cout<<"Case "<<++kase<<": ";
        Print(1, n);
        cout<<endl;
        p.clear();
    }
    return 0;
}

