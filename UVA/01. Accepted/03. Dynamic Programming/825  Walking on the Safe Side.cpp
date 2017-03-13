#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;
#define MAXN 1000
long long A[1000][1000];
long long dp[1000][1000];
long long n, R, C, t, next, k, len;
char buf[MAXN]={'\0'};

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

    string s;
    cin>>n;
    long long kase=0;
    while(n--)
    {
        memset(A, 0, sizeof(A));
        scanf("%lld%lld",&R,&C);

       for(int i=1;i<=R;i++)
       {
          scanf("%lld",&t);
          k=0;
          gets(buf);
          len=strlen(buf);
          for(int j=0;j<=len;j++)
          if(isdigit(buf[j]))
             k=k*10+buf[j]-'0';
          else
          {
              A[t][k]=1;
              k=0;
          }
       }
        /*for(long long i=1;i<=R;i++)
        {
            for(long long j=1;j<=C;j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }*/
        memset(dp, -1, sizeof(dp));

        if(kase)
            cout<<endl;

        cout<<rec(1,1)<<endl;

        kase++;




    }
    return 0;
}

