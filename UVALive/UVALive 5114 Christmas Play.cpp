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

#define INF 99999999999LL
long long a[20005];

int main()
{
    long long t, n, k, ans;
    cin>>t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        scanf("%lld %lld", &n, &k);
        for(int i=0;i<n;i++)
            scanf("%lld", &a[i]);
        sort(a, a+n);
        if(k==1)
            ans=0;
        else if(n==k)
            ans=a[n-1]-a[0];
        else
        {
            ans=INF;
            for(int i=0;i+k-1<n;i++)
            {
                ans=min(ans, a[i+k-1]-a[i]);
            }
        }
        printf("%lld\n", ans);


    }

}
