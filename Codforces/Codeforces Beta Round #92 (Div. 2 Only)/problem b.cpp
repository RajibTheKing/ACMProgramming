#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<sstream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int col[1000], a[1000], p[40500][10];
int num[10], num2[10];
int n;
int x;
string s1[10], s2[10];

void perm(int ind)
{
    int i;
    if(ind==n)
    {
        x++;

        for(int i=0;i<n;i++)
        {
            p[x][i]=a[i]+1;
        }

        return;
    }
    for(i=0;i<n;i++)
    {
        if(col[i]==0)
        {
            a[ind]=i;
            col[i]=1;
            perm(ind+1);
            col[i]=0;
        }
    }
}
main()
{
    int k, t;
    int f[12];
    stringstream ss;
    while(scanf("%d %d", &t, &k)==2)
    {
        for(int i=0;i<t;i++)
            cin>>s1[i];
        n=k;
        x=0;
        perm(0);
        long long min = 999999999;

        for(int i=1;i<=x;i++)
        {
            for(int j=0;j<k;j++)
                f[j]=p[i][j];
            for(int g=0;g<t;g++)
            {
                s2[g]="";
                for(int h=0;h<k;h++)
                    s2[g]+=s1[g][f[h]-1];
                ss.clear();
                ss<<s2[g];
                ss>>num2[g];

            }
            std::sort(num2, num2+t);
            if(num2[t-1]-num2[0]<min)
                min=num2[t-1]-num2[0];
        }
        cout<<min<<endl;
    }
    return 0;
}
