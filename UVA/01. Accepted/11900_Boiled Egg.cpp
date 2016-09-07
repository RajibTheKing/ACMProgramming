#include<stdio.h>
#include<algorithm>
#include<string.h>


main()
{
    int n, p, q, t, kase=0, i, s, ans;
    int a[100];
    scanf("%d", &t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        scanf("%d %d %d", &n, &p, &q);
        for(i=0;i<n;i++)
            scanf("%d", &a[i]);

        std::sort(a, a+n);

        s=0;
        ans=0;
        for(i=0;i<n;i++)
        {
            ans++;
            s=s+a[i];
            if(s>q)
            {
                ans--;
                break;
            }
            if(ans>p)
            {
                ans--;
                break;
            }
        }


       printf("Case %d: %d\n",++kase, ans);
    }
}
