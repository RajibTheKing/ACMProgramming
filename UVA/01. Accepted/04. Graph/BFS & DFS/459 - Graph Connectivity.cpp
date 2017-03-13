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

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


vector<int> adj[200];
vector<int> nodes;
int color[200];

void BFS(int x)
{
    queue<int> Q;
    Q.push(x);
    color[x]=1;
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        for(int i=0;i<adj[x].size();i++)
        {
            int p = adj[x][i];
            if(color[p]==0)
            {
                color[p]=1;
                Q.push(p);
            }
        }

    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    int T, kase=0;
    scanf("%d", &T);
    getchar();
    getchar();
    char str[100];
    char ch, ch1, ch2;


    for(int cs = 0; cs<T; cs++)
    {
        //cout<<"Fuck you: "<<T<<", "<<++kase<<endl;

        for(int i=0;i<200;i++)
            adj[i].clear();
        nodes.clear();
        memset(color, 0, sizeof(color));


        bool flag=false;
        while(scanf("%c", &ch1)==1)
        {
            int p, q;
            if(ch1=='\n') break;
            if(flag==false)
            {
                for(int i='A';i<=ch1;i++)
                {
                    nodes.pb(i);
                }
                flag=true;
                getchar();
                continue;
            }
            scanf("%c", &ch2);
            getchar();

            //printf("Here: %c %c\n", ch1, ch2);

            p = (int) ch1;
            q = (int) ch2;

            adj[p].pb(q);
            adj[q].pb(p);
            nodes.pb(p);
            nodes.pb(q);

        }
        int kount=0;
        for(int i=0;i<nodes.size();i++)
        {
            if(color[nodes[i]]==0)
            {
                kount++;
                BFS(nodes[i]);
            }

        }
        if(cs) cout<<endl;
        cout<<kount<<endl;
    }

    return 0;
}

