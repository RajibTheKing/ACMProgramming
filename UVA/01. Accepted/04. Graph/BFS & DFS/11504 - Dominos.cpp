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
using namespace std;
vector<int>adj[100010],ar;
bool taken[100010];
void take(int p)
{
    int j,v;
    taken[p]=1;
    for(j=0;j<adj[p].size();j++)
    {
        v=adj[p][j];
        if(taken[v]==0)
        take(v);
    }
}
int main()
{
    int t,n,m,cnt,u,v,i;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>m;
        ar.clear();
        memset(taken,0,sizeof(taken));
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(i=1;i<=n;i++)
        {
            if(taken[i]==0)
            {
                ar.push_back(i);
                take(i);
            }
        }
        memset(taken,0,sizeof(taken));
        for(i=ar.size()-1;i>=0;i--)
        {
            if(taken[ar[i]]==0)
            {
                cnt++;
                take(ar[i]);
            }
        }
        cout<<cnt<<endl;
    }



}
