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
typedef long long LL;
int main()
{
    LL stone[55][55];

    LL t, Ans, kase = 0, m, n, sum;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld", &m, &n);
        //bool flag=false;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%lld",  &stone[i][j]);

        Ans = 0;
        for(int i=0;i<m;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
                sum+=stone[i][j];

            Ans^=sum;

        }

        if(Ans)
            printf("Case %lld: Alice\n", ++kase);
        else
            printf("Case %lld: Bob\n", ++kase);


    }

}
