#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
int flag[2005], t1, t2;
bool color[2005];

vector<int> adj[2005];

void BFS(int x)
{
    queue<int> Q;
    Q.push(x);
    color[x]=true;
    t1++;
    while(!Q.empty())
    {

        x = Q.front(); Q.pop();
        for(int j=0;j<adj[x].size();j++)
        {

            if(color[adj[x][j]]==false)
            {
                if(flag[x]==1)
                {
                    flag[adj[x][j]]=2;
                    t2++;
                }
                else if(flag[x]==2)
                {
                    flag[adj[x][j]]=1;
                    t1++;
                }

                Q.push(adj[x][j]);
                color[adj[x][j]]=true;
            }
        }
    }
}


int input()
{
    memset(color, false, sizeof(color));
    memset(flag, -1, sizeof(flag));

    int n, m, i, j, k, u, v;
    cin>>n>>m;

    for(i=1;i<=m;i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int sum1=0, sum2=0;

    for(i=0;i<2005;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            t1=0;t2=0;
            if(flag[i]==-1)
            {
                flag[i]=1;
                BFS(i);

                if(t1>t2)
                {
                    sum1+=t1;
                    sum2+=t2;
                }
                else
                {
                    sum1+=t2;
                    sum2+=t1;
                }
            }
        }
    }

    for(i=0;i<2005;i++)
        adj[i].clear();


    return sum1;
}
int main()
{
    int T, ans, kase=0;
    cin>>T;
    while(T--)
    {
        ans = input();
        printf("Case %d: %d\n", ++kase, ans);
    }

}


