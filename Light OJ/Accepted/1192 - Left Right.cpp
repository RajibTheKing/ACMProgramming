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
    LL a[500], Gray[500], White[500];
    LL t, Ans, kase = 0, k;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(int i=0;i<k;i++)
            cin>>Gray[i]>>White[i];


        Ans = White[0]-Gray[0]-1;
        for(int i=1;i<k;i++)
        {
            Ans^=White[i]-Gray[i]-1;
        }

        if(Ans)
            printf("Case %lld: Alice\n", ++kase);
        else
            printf("Case %lld: Bob\n", ++kase);

    }

}
