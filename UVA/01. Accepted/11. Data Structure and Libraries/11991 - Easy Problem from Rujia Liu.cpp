#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;
#define SZ 100100

main()
{
    int n, m, aa, bb,ans;
    int a[SZ];
    map<int, vector<int> > M;
    while(scanf("%d %d", &n, &m)==2)
    {
        M.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
            M[a[i]].push_back(i);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d", &aa, &bb);
            if(M[bb].size()>=aa)
                ans = M[bb][aa-1] + 1;
            else
                ans=0;
            printf("%d\n", ans);


        }
    }
}
