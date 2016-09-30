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
#define INF 999999
using namespace std;
typedef long long LL;
struct Node
{
    int name;
    int distance;
    int parent;
    bool operator<(const Node &temp)const
	{
		return temp.distance<distance;
	}

};

priority_queue<Node> Q;
vector<int> Adj[500];
Node Set[500];
Node S[500];
map<int, bool> color;

void Initialize(int n, int start)
{
    color.clear();

    for(int i=0;i<n;i++)
    {
        Set[i].name=i;
        Set[i].distance=INF;
        Set[i].parent=-1;
    }

    Set[start].distance=0;
    Q.push(Set[start]);
    return;
}


void PRINT_ADJ(int n)
{
    cout<<"Here is the Adjecency matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        printf("For, %d: ", i);
        for(int j=0;j<Adj[i].size();j++)
        {
            cout<<Adj[i][j]<<" ";

        }
        cout<<endl;
    }
}

int main()
{
    freopen("rrr.txt", "r", stdin);
    int t, N, R, s, d, ans;
    int u, v;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {

        ans=0;
        scanf("%d %d", &N, &R);
        for(int i=0;i<R;i++)
        {
            scanf("%d %d", &u, &v);
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        scanf("%d %d", &s, &d);
        Initialize(N, s);
        Node U, V;
        //PRINT_ADJ(N);

        while(!Q.empty())
        {
            int i, j;
            U = Q.top(); Q.pop();
            i=U.name;
            for(j=0;j<Adj[i].size();j++)
            {
                //Relax(Set[U.name], Set[Adj[U.name][i]], 1);
                if(Set[Adj[i][j]].distance > Set[i].distance+1)
                {
                    Set[Adj[i][j]].distance = Set[i].distance+1;
                    Set[Adj[i][j]].parent = i;

                    Q.push(Set[Adj[i][j]]);
                }
            }
        }

        ans = Set[d].distance;
        int start, end=d;
        for(int i=0;i<N;i++)
        {
            if(i==s) continue;
            for(int p=0;p<N;p++)
            {
                S[p]=Set[p];
                S[p].distance=INF;
            }
            start=i;
            S[start].distance=Set[start].distance;

            Q.push(S[start]);
            int q=i;
            while(!Q.empty())
            {
                U = Q.top(); Q.pop();
                i=U.name;
                for(int j=0;j<Adj[i].size();j++)
                {
                //Relax(Set[U.name], Set[Adj[U.name][i]], 1);
                    if(S[Adj[i][j]].distance > S[i].distance+1)
                    {
                        S[Adj[i][j]].distance = S[i].distance+1;
                        S[Adj[i][j]].parent = i;

                        Q.push(S[Adj[i][j]]);
                    }
                }

            }
            if(ans<S[end].distance)
                ans = S[end].distance;

            i=q;
        }

//        cout<<"N = "<<N<<endl;
//        for(int i=0;i<N;i++)
//           cout<<Set[i].distance<<endl;
        printf("Case %d: %d\n", kase, ans);
        for(int i=0;i<N;i++)
            Adj[i].clear();

    }
    return 0;
}
