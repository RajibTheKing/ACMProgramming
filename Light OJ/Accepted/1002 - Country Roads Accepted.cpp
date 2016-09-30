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
#define INF 99999

int Cost[505][505];
int Key[505];
int Parent[505];
int color[505], n, M;
vector<int> City[505];

int Extract_Min()
{
    int k=-1;
    M = INF;

    for(int i=0;i<n;i++)
    {
        if(color[i]) continue;

        if(M>Key[i])
        {
            M=Key[i];
            k=i;
        }
    }
    //cout<<"Returned: "<<k<<endl;
    return k;
}

void Print()
{
    for(int p=0;p<n;p++)
        printf("%7d", Key[p]);
    cout<<endl;
    for(int p=0;p<n;p++)
        printf("%7d", color[p]);
    cout<<endl;
    for(int p=0;p<n;p++)
        printf("%7d", Parent[p]);
    cout<<endl;
}
int main()
{
    //freopen("data.txt", "r", stdin);
    int t, u, v, w,  m, position, kount;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {

        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++)
        {
            Key[i]=INF;
            Parent[i]=INF;
            for(int j=0;j<n;j++)
                Cost[i][j]=INF;
        }

        for(int i=0;i<m;i++)
        {

            scanf("%d %d %d", &u, &v, &w);
            Cost[u][v] = min(Cost[u][v], w);
            Cost[v][u] = min(Cost[v][u], w);

            City[u].push_back(v);
            City[v].push_back(u);
        }

        scanf("%d", &position);

        //cout<<"Complete"<<endl;
        memset(color, 0, sizeof(color));
        Key[position]=0;
        Parent[position]=-1;


        for(kount=1;kount<n;kount++)
        {
            //Print();

            u = Extract_Min();
            //cout<<u<<endl;
            if(u==-1) break;
            for(int j=0;j<City[u].size();j++)
            {
                //cout<<City[u].size()<<"Csss"<<endl;
                v = City[u][j];
                if(color[v]) continue;

                if(Cost[u][v]<Key[v])
                {
                    Parent[v]=u;
                    Key[v]=Cost[u][v];
                }
            }

            color[u]=1;
        }




        printf("Case %d:\n", kase);

        for(int i=0;i<n;i++)
        {
            int Max=-1;
            int j=i;
            if(Max<Key[j]) Max=Key[j];
            while(j!=position)
            {
                j=Parent[j];
                if(j==position) break;
                if(j==INF)
                {
                    Max=-1;
                    break;
                }

                if(Max<Key[j]) Max=Key[j];
            }
            if(Max!=-1)
                printf("%d\n", Max);
            else
                printf("Impossible\n");

        }
        for(int i=0;i<n;i++)
            City[i].clear();
    }
}
