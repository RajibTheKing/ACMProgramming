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
using namespace std;

vector<string> Set;
map<string, vector<string> >Adj;
map<string, int> color;
map<string, bool> check;

bool flag;

void DFS_Visit(string u)
{
    color[u]=1;
    for(int i=0;i<Adj[u].size();i++)
    {
        if(color[Adj[u][i]]==0&&flag==true)
            DFS_Visit(Adj[u][i]);

        else flag=false;
    }

}

void Clear_All(void)
{
    Set.clear();
    Adj.clear();
    color.clear();
    check.clear();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, m;
    string U, V;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {

        Clear_All();
        scanf("%d", &m);

        for(int i=0;i<m;i++)
        {
            cin>>U>>V;
            Adj[U].push_back(V);
            if(check[U]==false)
            {
                Set.push_back(U);
                check[U]=true;
            }
            if(check[V]==false)
            {
                Set.push_back(V);
                check[V]=true;
            }
        }

        /*for(int i=0;i<Set.size();i++)
        {
            cout<<Set[i]<<": ";
            for(int j=0;j<Adj[Set[i]].size();j++)
            {
                cout<<Adj[Set[i]][j]<<",  ";

            }
            cout<<endl;
        }*/

        flag=true;

        for(int i=0;i<Set.size();i++)
        {
            color.clear();
            DFS_Visit(Set[i]);
            if(flag==false) break;
        }


        if(flag==true)
            printf("Case %d: Yes\n", kase);
        else
            printf("Case %d: No\n", kase);


    }
    return 0;
}

