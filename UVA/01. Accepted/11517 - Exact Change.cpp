#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

#define sz 25005
#define INF 999999
int dp[sz];
int s[sz];
int main()
{
    //freopen("data.txt", "w", stdout);
    int t, price, n, coin[105];
    cin>>t;
    while(t--)
    {
        cin>>price;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>coin[i];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<sz;i++) s[i]=INF;
        s[0]=0;
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=15000;j>=0;j--)
            {
                if(dp[j])
                {
                    dp[j+coin[i]]=1;
                    s[j+coin[i]] = min(s[j+coin[i]], s[j]+1);
                }
            }
        }

//        for(int i=0;i<=10000;i++)
//            cout<<s[i]<<" "<<i<<endl;


        for(int j=price;;j++)
        {
            if(dp[j]==1)
            {
                cout<<j<<" "<<s[j]<<endl;
                break;
            }
        }



    }


    return 0;
}


