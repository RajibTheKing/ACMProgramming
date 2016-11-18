#include<bits/stdc++.h>

using namespace std;
#define SZ 200005
vector<int> adj[200005];
int arr[SZ];
int color[SZ];
void BFS(int x)
{
    int nowColor = arr[x];
    queue<int> Q;
    while(!Q.empty())
    {
        Q.pop();
    }
    Q.push(x);
    color[x]=1;
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        for(int i=0;i<adj[x].size();i++)
        {
            int y = adj[x][i];
            if(color[y]==0 && arr[y]==nowColor)
            {
                Q.push(y);
                color[y]=1;
            }
        }
    }
    return;
}
int main()
{
    int n, a, b;

    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &arr[i]);
        }

        for(int i=1;i<=(n-1);i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int black = 0, white = 0;
        memset(color, 0, sizeof(color));

        for(int i=1;i<=n;i++)
        {
            if(color[i]!=0) continue;

            if(arr[i]==1)
            {
                black++;
            }
            else
            {
                white++;
            }
            BFS(i);
        }

        cout<<black<<", "<<white<<endl;

        printf("%d\n", min(black, white));
    }
    return 0;
}
