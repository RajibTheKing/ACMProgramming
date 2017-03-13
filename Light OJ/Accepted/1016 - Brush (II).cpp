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
typedef long long LL;


vector<LL> Y;

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, N, w;
    int temp, ans;
    double d;
    scanf("%d", &t);
    for(int kase=1;kase<=t;kase++)
    {
        Y.clear();
        scanf("%d %d", &N, &w);
        for(int i=0;i<N;i++)
        {
            scanf("%d %d", &temp, &temp);
            Y.push_back(temp);

        }
        sort(&Y[0], &Y[N]);

        LL start, kount=0;
        int i, j;
        for(i=0;i<N;)
        {
            start=Y[i];
            for(j=i+1;j<N;j++)
            {
                if(Y[j]-start> w) break;
            }
            i=j;
            kount++;

        }

        printf("Case %d: %d\n", kase, kount);
    }



    return 0;
}

