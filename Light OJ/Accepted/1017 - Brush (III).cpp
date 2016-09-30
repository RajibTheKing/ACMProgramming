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


int dp[500][500];
vector<int> Y;
int N, K, w, ans;

int rec(int curr, int k)
{
    if(k>=K)
    {
        return 0;
    }
    if(curr>N-1)
    {
        return 0;
    }

    if(dp[curr][k]!=-1) return dp[curr][k];

    int &ret=dp[curr][k];

    ret  = rec(curr+1, k);


    int start = Y[curr];

    int j, q=1;

    for(j=curr+1;j<N;j++)
    {

        if(Y[j]-start >w)
            break;
        q++;
    }

    ret  = max(ret, rec(curr+q, k+1) + q);



    return ret;

}

int main()
{
    freopen("input.txt", "r", stdin);

    int t;
    int temp;
    double d;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {
        Y.clear();
        scanf("%d %d %d", &N, &w, &K);
        for(int i=0;i<N;i++)
        {
            scanf("%d %d", &temp, &temp); // First temp is Useless....
            Y.push_back(temp);

        }
        sort(&Y[0], &Y[N]); // Sorting Y Co-Ordinate

        memset(dp, -1, sizeof(dp));

        ans = rec(0,0);     // Calling Recursion Indx=0, Maximum Move = 0

        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}

