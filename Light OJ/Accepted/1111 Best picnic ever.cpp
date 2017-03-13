#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>

using namespace std;
vector<int> adj[1005];
int color[1005];

void BFS(int x, int f[])
{
    color[x]++;
    f[x]=0;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front(); Q.pop();
        for(int j=0;j<adj[x].size();j++)
        {
            if(f[adj[x][j]]==-1)
            {
                f[adj[x][j]]=0;
                color[adj[x][j]]++;
                Q.push(adj[x][j]);

            }
        }
    }
}


int input(int k, int n, int m)
{


    int kount = 0, man[105],u , v;
    int flag[1005];
    int i, j;

    for(i=1;i<=k;i++)
        cin>>man[i];

    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }



    for(i=1;i<=k;i++)
    {
        memset(flag, -1, sizeof(flag));
        BFS(man[i], flag);
    }

    for(i=1;i<=n;i++)
        if(color[i]==k)
            kount++;

    memset(color, 0, sizeof(color));
    for(int q=0;q<=n;q++)
        adj[q].clear();

    return kount;


}
int main()
{
    int T, kase = 0, ans, k, n, m;
    cin>>T;
    while(T--)
    {
        scanf("%d %d %d", &k, &n, &m);
        ans = input(k, n, m);

        printf("Case %d: %d\n", ++kase, ans);
    }
}
