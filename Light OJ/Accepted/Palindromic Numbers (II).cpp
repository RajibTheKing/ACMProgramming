#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;

int main()
{
    string a, b, c;
    int n, i, j, k, kase = 0;
    cin>>n;
    while(n--)
    {
        cin>>a;
        k = a.length();
        bool flag = true;
        for(i=0, j=k-1;i<=k/2&&j>=k/2 ;i++, j--)
        {
            if(a[i]!=a[j])
            {

                flag=false;
                break;
            }


        }
        if(flag)
            printf("Case %d: Yes\n", ++kase);
        else
            printf("Case %d: No\n", ++kase);
    }

    return 0;
}
