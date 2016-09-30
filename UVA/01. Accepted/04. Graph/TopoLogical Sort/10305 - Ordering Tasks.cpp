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
    int name, discover, finish;
};

Node Set[105], R[105];
vector<int> Adj[105];
map<int, bool> color;
int kount;

void DFS_Visit(int x)
{
    Set[x].name=x;
    Set[x].discover=++kount;
    for(int i=0;i<Adj[x].size();i++)
    {
        if(color[Adj[x][i]]==false)
        {
            color[Adj[x][i]]=true;
            DFS_Visit(Adj[x][i]);
        }
    }
    Set[x].finish=++kount;
}

bool comp(Node p, Node q)
{
    return p.finish>q.finish;
}

int main()
{
    //freopen("test.txt", "r", stdin);

    int Test, kase=0, N, M, u, v;


    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        color.clear();
        for(int i=0;i<M;i++)
        {
            scanf("%d %d", &u, &v);
            Adj[u].push_back(v);
        }
        kount=0;

        for(int i=1;i<=N;i++)
        {
            if(color[i]==false)
            {
                color[i]=true;
                DFS_Visit(i);
            }
        }
        for(int i=1;i<=N;i++)
            R[i-1]=Set[i];

        sort(&R[0], &R[N], comp);

        for(int i=0;i<N;i++)
        {
            if(i==0)
                printf("%d", R[i].name);
            else
                printf(" %d", R[i].name);
        }
        cout<<endl;

        for(int i=0;i<=N;i++)
            Adj[i].clear();

    }

    return 0;
}

