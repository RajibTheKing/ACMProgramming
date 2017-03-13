#include<iostream>
#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<math.h>
#include<cmath>
#include<sstream>
#include<algorithm>
#define inf 11111111
using namespace std;
int dx[]={-2,-2,-1,1,2, 2, 1,-1};
int dy[]={-1, 1, 2,2,1,-1,-2,-2};

int dr[]={-1,-1, -1,  0, 1, 1, 1, 0};
int dc[]={-1, 0,  1,  1, 1, 0,-1,-1};

string a[110];
bool flag[110][110];
int p[110][110],dis[110][110];

int m,n;

int bfs(int u,int v)
{
    queue<int>Q;
    int x,y,r,c,i;
    Q.push(u);
    Q.push(v);
    dis[u][v]=0;
    flag[u][v]=1;
    while(!Q.empty())
    {
        x=Q.front();Q.pop();
        y=Q.front();Q.pop();
        for(i=0;i<8;i++)
        {
            r=x+dr[i];
            c=y+dc[i];

            if(r>=0&&r<m&&c>=0&&c<n&&flag[r][c]==0&&a[r][c]!='Z'&&a[r][c]!='z')
            {
                if(a[r][c]=='B')return dis[x][y]+1;
                else
                {
                    dis[r][c]=dis[x][y]+1;
                    Q.push(r);
                    Q.push(c);
                    flag[r][c]=1;
                }
            }
        }
    }
    return -1;

}

int main()
{
    int t,i,j,u,v,uu,vv,x,y;
    //freopen("test.txt", "r", stdin);

    cin>>t;
    while(t--)
    {
        memset(flag,0,sizeof(flag));
        memset(dis,0,sizeof(dis));

        cin>>m>>n;
        for(i=0;i<m;i++)
            a[i].clear();
        for(i=0;i<m;i++)
        {
            cin>>a[i];
        }

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='A')
                {
                    u=i;
                    v=j;
                }
                else if(a[i][j]=='B')
                {
                    uu=i;
                    vv=j;
                }
                else if(a[i][j]=='Z')
                {
                    for(int k=0;k<8;k++)
                    {
                        x=i+dx[k];
                        y=j+dy[k];
                        if(x>=0&&y>=0&&x<m&&y<n&&a[x][y]=='.')
                        {
                            a[x][y]='z';
                        }
                    }
                }

            }
        }


        int ans=bfs(u,v);

        if(ans==-1)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",ans);

    }
    return 0;
}

