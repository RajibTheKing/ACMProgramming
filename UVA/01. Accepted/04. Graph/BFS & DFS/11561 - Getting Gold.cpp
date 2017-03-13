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

int ROW, COL;
string board[100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


bool isValid(int i, int j)
{
    if(i<0||i>=ROW||j<0||j>COL||board[i][j]=='#') return false;
    return true;

}

int VisitBFS(int x, int y)
{
    int kount=0;
    queue<int> Q;
    bool f=true;
    for(int j=0; j<4; j++)
    {
        int m, n;
        m = x+dx[j];
        n = y+dy[j];
        if(board[m][n]=='T')
            f=false;
    }

    if(f)
    {
        //cout<<"Here i pushed: "<<p<<", "<<q<<endl;
        Q.push(x);
        Q.push(y);
        board[x][y]='#';
    }
    while(!Q.empty())
    {
        x=Q.front(); Q.pop();
        y=Q.front(); Q.pop();
        //cout<<x<<", "<<y<<endl;
        for(int i=0;i<4;i++)
        {
            int p, q;
            p=x+dx[i];
            q=y+dy[i];
            if(isValid(p, q))
            {
                if(board[p][q]=='G')
                    kount++;
                board[p][q]='#';
                bool flag=true;
                for(int j=0;j<4;j++)
                {
                    int m, n;
                    m = p+dx[j];
                    n = q+dy[j];
                    if(board[m][n]=='T')
                        flag=false;
                }

                if(flag)
                {
                    //cout<<"Here i pushed: "<<p<<", "<<q<<endl;
                    Q.push(p);
                    Q.push(q);
                }


            }

        }

    }
    return kount;
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int T, ans;

    while(scanf("%d %d\n",&COL,&ROW)!=EOF)
    {
       // getchar();
        for(int i=0;i<ROW;i++)
            cin>>board[i];

        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                //printf("%c", board[i][j]);
                if(board[i][j]=='P')
                {
                    ans = VisitBFS(i, j);

                }
            }

        }
        cout<<ans<<endl;


    }



    return 0;
}

