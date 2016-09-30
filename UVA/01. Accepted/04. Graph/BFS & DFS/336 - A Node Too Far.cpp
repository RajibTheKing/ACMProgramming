#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>
#define INF 99999
#define pi 3.1415926535897932384626433832795
using namespace std;

map<int, int> Set;
map<int, vector<int> > Adj;
map<int, bool> check;
vector<int> Nodes;
map<int, bool> color;

int BFS(int start, int TTL)
{
    int x;
    Set[start]=0;
    queue<int> Q;
    Q.push(start);
    color.clear();

    color[start]=true;
    int kount=1;
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        for(int i=0;i<Adj[x].size();i++)
        {
            if(Set[x]+1<=TTL&&Set[Adj[x][i]]>Set[x]+1&&color[Adj[x][i]]==false)
            {
                color[Adj[x][i]]=true;
                kount++;
                Set[Adj[x][i]]=Set[x]+1;
                //cout<<"Found: "<<Adj[x][i]<<endl;

                Q.push(Adj[x][i]);
            }

        }
    }
    return kount;

}
int main()
{
    //freopen("test.txt", "r", stdin);

    int edges, kase=0, u, v, start, TTL, ans;

    while(cin>>edges)
    {
        if(edges==0) break;

        Adj.clear();
        Nodes.clear();
        check.clear();
        Set.clear();
        for(int i=0;i<edges;i++)
        {
            scanf("%d %d", &u, &v);
            Adj[u].push_back(v);
            Adj[v].push_back(u);
            if(check[u]==false)
            {
                check[u]=true;
                Nodes.push_back(u);
            }
            if(check[v]==false)
            {
                check[v]=true;
                Nodes.push_back(v);
            }
        }

        //cout<<"Nodes: "<<Nodes.size()<<endl;

        while(cin>>start>>TTL)
        {
            if(start==0&&TTL==0) break;

            for(int i=0;i<Nodes.size();i++)
                Set[Nodes[i]]=INF;

            ans = Nodes.size()-BFS(start, TTL);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++kase, ans, start, TTL);
        }


    }

    return 0;
}

