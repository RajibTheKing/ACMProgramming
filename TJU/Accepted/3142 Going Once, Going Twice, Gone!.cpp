#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>

using namespace std;
int main()
{
    int n, m;
    int a[1005];
    int i, j;
    int ans1, ans2, t, p, q;

    while(cin>>n>>m)
    {
        for(i=0;i<m;i++)
            cin>>a[i];

        sort(&a[0], &a[m]);



        ans2 = 0;

        for(i=0;i<m;i++)
        {
            t=n;
            p=a[i];
            q= 0;
            for(j=i;j<m;j++)
            {
                q+=p;
                t--;
                if(t==0) break;
            }
            if(q>ans2)
            {
                ans1=p;
                ans2=q;
            }
        }
        printf("%d %d\n", ans1, ans2);


    }

    return 0;
}
