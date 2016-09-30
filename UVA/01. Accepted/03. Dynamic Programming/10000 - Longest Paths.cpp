#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[200];
int dp[200][200];


int find_path(int cur, int destination)
{

    int &ret = dp[cur][destination];
    if(ret!=-1)
        return ret;
    else
    for(int i=0;i<adj[cur].size();i++)
    {
        ret=max(ret, 1+find_path(adj[cur][i], destination));
    }
    return ret;
}
int main()
{
    freopen("input.txt", "r",  stdin);
    int n, s, p, q, kase=0, ans, end_node;
    while(cin>>n)
    {
        if(n==0) break;

        for(int i=0;i<500;i++)
        {
            adj[i].clear();
        }

        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                dp[i][j]=-1;
            }
            dp[i][i]=0;
        }

        cin>>s;
        while(cin>>p>>q)
        {
            if(p==0&&q==0) break;
            adj[p].push_back(q);
        }


        ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(find_path(s,i)>ans)
            {
                ans=find_path(s,i);
                end_node=i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++kase,s,ans,end_node);
    }
    return 0;
}
