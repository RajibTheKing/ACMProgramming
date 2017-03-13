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
#include <sstream>
using namespace std;
#define INF 9999999
#define SZ 650

int n;

bool DP[33][SZ][SZ];

int Weight[33];


void rec(int cur, int i, int j)
{
    //cout<<"Cur: "<<cur<<" N: "<<n<<endl;

    if(DP[cur][i][j]==true) return;
    DP[cur][i][j]=true;

    if(cur==n) return;

    rec(cur+1, i+Weight[cur], j);
    rec(cur+1, i, j+Weight[cur]);
    rec(cur+1, i, j);

    return;

}

int main()
{
    int t, MaximumDiff, a, b, c, temp, kase=0;
    scanf("%d", &t);
    while(t--)
    {

        int sum=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &Weight[i]);
            sum+=Weight[i];
        }
        //cout<<sum<<endl;

        memset(DP, false, sizeof(DP));  //Initialize All as Not Visited

        rec(0, 0, 0);

        MaximumDiff = INF;

        /*for(int i=0;i<=sum;i++){
            for(int j=0;j<=sum;j++)
                cout<<DP[n-1][i][j]<<" ";
            cout<<endl;
        }*/

        for(int i=0;i<=sum;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                //cout<<"Enteded in this contidion...."<<endl;
                if(DP[n][i][j]==true)
                {
                    //cout<<"Enteded in this contidion...."<<endl;

                    a=i; b = j; c = sum-a-b;

                    temp = max(a,  max(b, c) ) - min( a, min(b, c) );

                    MaximumDiff = min (MaximumDiff, temp);
                }
            }
        }
        printf("Case %d: %d\n", ++kase, MaximumDiff);

    }
    return 0;
}


