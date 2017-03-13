
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

LL fact[1000000];



int main( )
{
    int T, kase=0;
    cin>>T;
    LL Q, n, sum, ans, down=5, top=1000000000, mid;
    bool flag;
    while(T--)
    {
        cin>>Q;
        down=1; top=1000000000;
        flag=false;
        while(down<top)
        {
            mid=(down+top)/2;
            //cout<<"mid: "<<mid<<endl;
            n=mid;
            sum=0;
            while(n)
            {
                sum+=n/5;
                n/=5;
            }
            //cout<<"sum: "<<sum<<endl;
            if(sum==Q)
            {
                flag=true;
                ans=mid;
            }
            if(sum<Q)
                down=mid+1;
            else
                top=mid;

        }
        sum=0;
        LL temp=down;
        while(down)
        {
            sum+=down/5;
            down/=5;

        }
        if(sum==Q)
            ans=temp;

        if(flag)
            printf("Case %d: %lld\n", ++kase, ans);
        else
            printf("Case %d: impossible\n", ++kase);

    }



    return 0;
}
