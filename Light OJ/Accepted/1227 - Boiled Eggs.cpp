#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int t, n, p, q, i;
    cin>>t;
    int a[100], sum, kase=0;

    while(t--)
    {
        memset(a, 0, sizeof(a));
        cin>>n>>p>>q;
        for(i=0;i<n;i++)
            cin>>a[i];
        std::sort(a, a+n);
        sum=0;
        for(i=1;i<=p&&i<=n;i++)
        {
            sum+=a[i-1];
            if(sum>q)
                break;
        }

        i--;

        printf("Case %d: %d\n", ++kase, i);

    }

    return 0;
}

