#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;
string a[10000];
int k,c,r,q[10000],q1[10000],front,rear;bool flag[1000][1000];
int bfs()
{
    int ct=0;
    while(front<rear)
    {
        int i,j;
        i=q[front];j=q1[front];
        if(j<c&&i-1>=0&&flag[i-1][j]==0&&a[i-1][j]=='.')
        {
            flag[i-1][j]=1;
            q[rear]=i-1;
            q1[rear++]=j;
            ct++;
        }
        if(i<r&&j-1>=0&&flag[i][j-1]==0&&a[i][j-1]=='.')
        {
            flag[i][j-1]=1;
            q[rear]=i;
            q1[rear++]=j-1;
            ct++;
        }
        if(i+1<r&&flag[i+1][j]==0&&a[i+1][j]=='.')
        {
            flag[i+1][j]=1;
            q[rear]=i+1;
            q1[rear++]=j;
            ct++;
        }
        if(j+1<c&&flag[i][j+1]==0&&a[i][j+1]=='.')
        {
            flag[i][j+1]=1;
            q[rear]=i;
            q1[rear++]=j+1;
            ct++;
        }
        front++;
    }
    return ct+1;
}

main()
{
    int test,i,j;
    cin>>test;
    while(test--)
    {


        memset(flag,0,sizeof(flag));
        memset(q,0,sizeof(q));
        memset(q1,0,sizeof(q1));
        rear=0;
        front=0;
        cin>>c>>r;

        for(i=0;i<r;i++)
        {
            a[i].clear();
            cin>>a[i];
            for(j=0;j<a[i].size();j++)
            {
                if(a[i][j]=='@')
                {
                    q[rear]=i;
                    q1[rear++]=j;
                }
            }
        }

        int ans=bfs();
        printf("Case %d: %d\n",++k,ans);
    }


}
