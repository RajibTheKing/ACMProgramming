#include<stdio.h>
#include<string.h>
main()
{
    int flag[1000];
    int a[1000];

    int i, t, k, count, max;

    while(1)
    {
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));
        i=-1;
        count = 0;
        max=0;


        scanf("%d", &t);
        if(t==-1) break;
        a[++i]=t;
        if(max<t) max=t;
        for(; ;)
        {
            scanf("%d", &t);
            if(t==0) break;
            a[++i]=t;
            if(max<t) max=t;
        }

        k=i;
        for(i=0;i<=k;i++)
        {
            flag[a[i]]=1;

        }


        for(i=0;i<=max;i++)
        {

            if(flag[i]==1)
                if(i%2==0)
                    if(flag[i/2]==1)
                        count++;
        }



        printf("%d\n", count);



    }
}
