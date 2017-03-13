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


int Trailing_Zero_Fact(int n)
{
    int r=0;
    while(n)
    {
        r+=n/5;
        n/=5;
    }
    return r;
}
int Trailing_Zero_Num(int n)
{
    int r=0;
    while(n)
    {
        if(n%10==0)
            r++;
        n/=10;

    }
    cout<<"For P: "<<r<<endl;
    return r;
}
int main( )
{
    int T, kase=0, n, r, p, q, ans;
    cin>>T;
    while(T--)
    {
        ans = 0;

        cin>>n>>r>>p>>q;
        ans += Trailing_Zero_Fact(n);
        ans -= Trailing_Zero_Fact(r);
        ans -= Trailing_Zero_Fact(n-r);
        ans += Trailing_Zero_Num(p)*q;

        printf("Case %d: %d\n", ++kase, ans);
    }

    return 0;
}

