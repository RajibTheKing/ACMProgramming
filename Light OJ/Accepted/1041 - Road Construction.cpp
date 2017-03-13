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
#define INF 9999999

struct Node
{
    string name;
    int cost;
    string parent;
    int key;
    bool operator<(const Node &temp) const
    {
        return temp.cost<cost;
    }
};

map<string, vector<Node> > City;
map<string, bool> Check;
priority_queue<Node> Q;
vector<Node>R;
map<string, bool> color;




int MST_Prim(int Num)
{
    Node U, V;
    int ans=0, kount=0;

    while(!Q.empty())
    {
        U = Q.top(); Q.pop();
        if(color[U.name]==true) continue;
        kount++;
        //cout<<U.name<<" "<<U.cost<<" "<<U.key<<endl;

        ans+=U.key;

        for(int i=0;i<City[U.name].size();i++)
        {
            V = City[U.name][i];
            if(color[V.name]==false&&V.cost<V.key)
            {

                V.parent = U.name;
                V.key = V.cost;
                Q.push(V);
            }
        }

        color[U.name]=true;

    }
    //cout<<kount<<endl;
    if(kount!=Num) return -1;
    return ans;
}
int main()
{
    //freopen("data.txt", "r", stdin);
    Node U, V;

    string city1, city2;
    int t, m, cost;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {
        color.clear();
        Check.clear();
        R.clear();

        scanf("%d", &m);
        for(int i=0;i<m;i++)
        {
            cin>>city1>>city2>>cost;


            V.name=city1;
            V.cost=cost;
            V.key = INF;
            V.parent=-1;

            U.name = city2;
            U.cost = cost;
            U.key = INF;
            U.parent=-1;

            City[V.name].push_back(U);
            City[U.name].push_back(V);

            if(Check[city1]==false)
            {
                R.push_back(V);
                Check[city1]=true;
            }
            if(Check[city2]==false)
            {
                R.push_back(U);
                Check[city2]=true;
            }

        }
        R[0].key=0;
        Q.push(R[0]);
        //cout<<R.size()<<endl;
        int result = MST_Prim(R.size());

        //cout<<"Result: "<<result<<endl;
        if(result==-1)
            printf("Case %d: Impossible\n", kase);
        else
            printf("Case %d: %d\n", kase, result);

        City.clear();
    }
    return 0;


}

