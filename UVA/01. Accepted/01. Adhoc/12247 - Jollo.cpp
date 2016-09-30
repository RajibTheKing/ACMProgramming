#include<iostream>
#include<map>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>

using namespace std;

bool comp(int a, int b)
{
    return a>b;
}
main()
{
    int princess[3], prince[2];
    int a, b, c, x,y, ans, Max;
    map<int, bool> M;
    while(cin>>a>>b>>c>>x>>y)
    {
        M.clear();
        if(a==0) break;
        princess[0]=a;
        princess[1]=b;
        princess[2]=c;
        prince[0]=x;
        prince[1]=y;
        M[a]=true;
        M[b]=true;
        M[c]=true;
        M[x]=true;
        M[y]=true;
        sort(&princess[0], &princess[3]);
        sort(&prince[0], &prince[2], comp);

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(prince[j]!=-1&&princess[i]>prince[j])
                {
                    prince[j]=-1;
                    princess[i]=-1;
                    break;
                }
            }
        }

        if(prince[0]==-1&&prince[1]==-1)
            ans=-1;
        else if(prince[0]!=-1&&prince[1]!=-1)
        {
            for(int i=1;i<=52;i++)
            {
                if(M[i]==false)
                {
                    ans=i;
                    break;
                }
            }
        }
        else
        {
            ans=-1;
            Max=-1;
            for(int i=0;i<3;i++)
                Max=max(Max, princess[i]);
            for(int i=Max+1;i<=52;i++)
            {
                if(M[i]==false)
                {
                    ans=i;
                    break;
                }
            }

        }
        cout<<ans<<endl;
    }
}
