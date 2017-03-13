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



LL GCD(LL a, LL b)
{
    if(b==0)
        return a;
    else
        return GCD(b, a%b);
}
int main()
{
    LL t,mod, kase=0;
    LL a, b, c, L, x, y, top, down, mid;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        cin>>L;
        top = 1000000000000;
        down = 1;
        while(1)
        {
            mid = (top+down)/2;
            c=mid;
            y = GCD(a, b);
            x = (a*b)/y;

            y = GCD(x, c);
            x = (x*c)/y;
            if(x==L) break;

            if(x<L)
        }

    }


    return 0;
}
