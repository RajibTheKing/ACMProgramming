#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

vector<int>adj[30005];
int maximum;

int kount[30005];
int BFS(int x, int f[], vector<int>distance[])
{
    memset(kount, 0, sizeof(kount));
    maximum=0;
    int temp = 0;
    f[x]=0;
    kount[x]=0;

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
                kount[adj[x][j]]=kount[x]+ distance[x][j];


                if(maximum<kount[adj[x][j]])
                {
                    maximum = kount[adj[x][j]];
                    temp = adj[x][j];
                }
                Q.push(adj[x][j]);

            }
        }
    }

    return temp;
}

int input(int n)
{
    vector<int>distance[30005];
    int max = 0;
    int i, j, k, u, v, w, start;
    int f[30005];



    for(i=0;i<n-1;i++)
    {
        cin>>u>>v>>w;
        if(i==0)
            start = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
        distance[u].push_back(w);
        distance[v].push_back(w);
    }

    memset(f, -1, sizeof(f));
    start = BFS(start, f, distance);
    memset(f, -1, sizeof(f));
    start = BFS(start, f, distance);
    max = maximum;


    for(i=0;i<n;i++){
        distance[i].clear();
        adj[i].clear();
    }

    return max;
}

main()
{
    int T, n, kase=0, ans;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans = input(n);
        printf("Case %d: %d\n", ++kase, ans);
    }
}
