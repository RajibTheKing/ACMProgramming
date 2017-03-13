#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;
typedef long long LL;


vector<int> Adj[500];
int color[500];


bool flag;

void DFS_Visit(int u)
{
    for(int i=0;i<Adj[u].size();i++)
    {
        if(color[Adj[u][i]]==0&&flag==true)
        {
            color[Adj[u][i]]=color[u]*-1;
            DFS_Visit(Adj[u][i]);
        }
        else
        {
            if(color[u]==color[Adj[u][i]])
            flag=false;
        }
    }
}
int main()
{
    int T, l, n, u, v;

    while(scanf("%d", &n)==1&&n)
    {

        scanf("%d", &l);
        for(int i=0;i<l;i++)
        {
            scanf("%d %d", &u, &v);
            Adj[u].push_back(v);
            Adj[v].push_back(u);

        }

        memset(color, 0, sizeof(color));
        //memset(parent, 0, sizeof(parent));
        flag=true;
        color[0]=1;
        DFS_Visit(0);
       // for(int i=0;i<n;i++)
            //cout<<"I: "<<i<<",  "<<color[i]<<endl;

        if(flag)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<": ";
            Adj[i].clear();

        }


    }

    return 0;
}
