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
using namespace std;

#define pi 3.1415926535897932384626433832795


vector<int> Adj[10005];
map<int, bool> color;
vector<int> Collect;


void DFS_Visit(int u)
{
    color[u]=true;
    for(int i=0;i<Adj[u].size();i++)
    {
        if(color[Adj[u][i]]==0)
            DFS_Visit(Adj[u][i]);
    }

}
void Clear_All(void)
{
    Collect.clear();
    color.clear();


}
int main()
{
    int kase=0, t, node, edge, u, v;
    scanf("%d", &t);

    while(t--)
    {
       Clear_All();


        scanf("%d %d", &node, &edge);
        for(int i=0;i<edge;i++)
        {
            scanf("%d %d", &u, &v);
            Adj[u].push_back(v);
        }
        color.clear();
        for(int i=1;i<=node;i++)
        {
            if(color[i]==false)
            {
                Collect.push_back(i);
                DFS_Visit(i);
            }
        }
        color.clear();
        int kount=0;

        for(int i=Collect.size()-1;i>=0;i--)
        {
            if(color[Collect[i]]==false)
            {
                kount++;
                DFS_Visit(Collect[i]);
            }
        }
        printf("Case %d: %d\n", ++kase, kount);



        for(int i=0;i<=node;i++)
            Adj[i].clear();


    }

    return 0;
}

