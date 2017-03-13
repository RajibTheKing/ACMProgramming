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
#include <queue>

#define pi 3.1415926535897932384626433832795
#define Mx 1000000
using namespace std;



vector<int> move;
int dp[Mx+1];

int main()
{
    int n, m, t;

    while(cin>>n)
    {
        cin>>m;
        move.clear();
        for(int i=0;i<m;i++)
        {
            cin>>t;
            move.push_back(t);
        }
        memset(dp, 0, sizeof(dp));
        dp[0]=1;                    // 1 is considered as LOSE
        for(int i=0;i<=n;i++)
        {
            if(dp[i]==1||dp[i]==0)
            {
                dp[i]=1;
                for(int j=0;j<move.size();j++)
                {
                    if(i+move[j]<=n)
                        dp[i+move[j]]=2;
                }
            }

        }
        if(dp[n]==1)
            printf("Ollie wins\n");
        else
            printf("Stan wins\n");


    }

    return 0;
}

