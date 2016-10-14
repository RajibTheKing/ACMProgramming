#include<bits/stdc++.h>
using namespace std;
#define SZ 50005

int adj[SZ];
int color[SZ];
int alreadyCalled[SZ];

int DFS(int x)
{
    color[x]=1;
    alreadyCalled[x]=1;
    int ret = 0;
    int cur = adj[x];
    if(color[cur]==0)
    {
        ret = 1+DFS(cur);
    }
    return ret;
}

int main()
{
    int T, kase = 0, N, u,v;
    cin>>T;
    while(T--)
    {
        scanf("%d", &N);
        memset(alreadyCalled, 0, sizeof(alreadyCalled));

        for(int i=0;i<N;i++)
        {
            scanf("%d %d", &u, &v);
            adj[u]=v;
            alreadyCalled[u]=-1;

        }
        int ans = -1;
        int item = -1;

        for(int i=0;i<=N;i++)
        {
            if(alreadyCalled[i]==-1)
            {
                memset(color, 0, sizeof(color));
                int now = DFS(i);
                if(now>ans)
                {
                    ans = now;
                    item = i;
                }
            }
        }

        printf("Case %d: %d\n", ++kase, item);


    }
    return 0;
}

/*
1
6
1 2
2 3
5 4
5 1
5 2
5 3
*/
