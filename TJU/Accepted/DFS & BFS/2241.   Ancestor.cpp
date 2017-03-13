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

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;

typedef struct Node
{
    int discover;
    int finish;
};


vector<int> adj[10005];
map<int, bool> color;
map<int, Node> Set;

int kount;

void DFS_Visit(int x)
{
    Set[x].discover = ++kount;
    for(int i=0;i<adj[x].size();i++)
    {
        if(color[adj[x][i]]==false)
        {
            color[adj[x][i]]=true;
            DFS_Visit(adj[x][i]);
        }
    }
    Set[x].finish=++kount;
}

int main()
{
    int Test, kase=0, N,M, u, v, a, b;
    scanf("%d", &Test);
    getchar();

    while(Test--)
    {



        color.clear();
        Set.clear();

        scanf("%d", &N);
        for(int i=1;i<N;i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        kount = -1;
        color[0]=true;
        DFS_Visit(0);

        scanf("%d", &M);
        for(int i=0;i<M;i++)
        {
            scanf("%d %d", &a, &b);
            if(Set[a].discover<Set[b].discover && Set[a].finish>Set[b].finish)
                printf("Yes\n");
            else
                printf("No\n");

        }
        printf("\n");

        for(int i=0;i<=N;i++)
            adj[i].clear();

    }

    return 0;
}

