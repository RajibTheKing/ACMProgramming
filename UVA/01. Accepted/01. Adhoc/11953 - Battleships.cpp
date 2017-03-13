#include<bits/stdc++.h>
using namespace std;
#define SZ 200

int dx[] = {1 ,0 ,-1, 0};
int dy[] = {0, 1  ,0 ,-1};
int color[SZ][SZ];
string board[SZ];
int n;

bool isValid(int x, int y)
{
    if(x<0||x>=n) return false;
    if(y<0||y>=n) return false;
    if(board[x][y]=='.') return false;
    if(color[x][y]==1) return false;

    return true;
}
void BFS(int x, int y)
{
    queue<int> Q;
    while(!Q.empty())
    {
        Q.pop();
    }

    Q.push(x);
    Q.push(y);
    color[x][y]=1;
    while(!Q.empty())
    {
        int tx, ty;
        tx = Q.front(); Q.pop();
        ty = Q.front(); Q.pop();

        for(int i=0;i<4;i++)
        {
            int xx = dx[i]+tx;
            int yy = dy[i]+ty;
            if(isValid(xx,yy))
            {
                color[xx][yy]=1;
                Q.push(xx);
                Q.push(yy);
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r+", stdin);
    int Test;
    cin>>Test;
    int kase=0;
    while(Test--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>board[i];
        }

        int knt = 0;
        memset(color, 0, sizeof(color));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isValid(i,j) && board[i][j]=='x')
                {
                    knt++;
                    BFS(i,j);
                }
            }
        }
        //cout<<knt<<endl;
        printf("Case %d: %d\n", ++kase, knt);
    }

    return 0;
}
