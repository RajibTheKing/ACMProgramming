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



int main()
{
    int t, b, mod, kase=0;
    string a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        if(b<0) b=b*(-1);
        mod=0;
        int k=a.size();
        for(int i=0;i<k;i++)
        {
            if(a[i]=='-') continue;

            mod = (mod*10 + (a[i]-'0'))%b;
        }

        if(mod==0)
            printf("Case %d: divisible\n", ++kase);
        else printf("Case %d: not divisible\n", ++kase);
    }


    return 0;
}
