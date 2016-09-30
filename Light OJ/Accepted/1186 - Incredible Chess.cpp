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
    int a[500], b[500];

    int t, kase=0, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int j=0;j<n;j++)
            cin>>b[j];

        int sum = b[0]-a[0]-1;


        for(int i=1;i<n;i++)
        {
            sum^=b[i]-a[i]-1;

        }
        if(sum==0)

            printf("Case %d: black wins\n", ++kase);

        else
            printf("Case %d: white wins\n", ++kase);



    }
}
