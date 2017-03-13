#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;
#define MAXN 1000
long long A[1000][1000];
long long dp[1000][1000];
long long n, R, C,len;


long long rec(long long i, long long j)
{

    if(i==R&&j==C) return 1;
    if(i>R||j>C) return 0;
    if(A[i][j]==1) return 0;

    long long &ret = dp[i][j];
    if(ret!=-1) return ret;
    ret = rec(i, j+1) + rec(i+1, j);
    return ret;

}

int main()
{
    //freopen("test.txt", "r", stdin);

    while(cin>>R>>C)
    {
        if(R==0&&C==0) break;

        int x, y;

        memset(A, 0, sizeof(A));
        //scanf("%lld%lld",&R,&C);
       cin>>len;
       for(int i=0;i<len;i++)
       {
          cin>>x>>y;
          A[x][y]=1;
       }
        /*for(long long i=0;i<=R;i++)
        {
            for(long long j=0;j<=C;j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }*/
        memset(dp, -1, sizeof(dp));
        long long ans=rec(0,0);
        if(ans==0)
            printf("There is no path.\n");
        else if(ans==1)
            printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else
            printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", ans);


    }
    return 0;
}

