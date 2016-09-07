#include<stdio.h>
main()
{

    int n, i, j,sum, count;
    int t[2], c[2];
    int  avg;
    int a[1005];
    while(scanf("%d", &n)==1)
    {
        sum=0;
        for(i=0;i<n;i++)
            scanf("%d", &a[i]);

        for(i=0;i<n;i++)
            sum=sum+a[i];

        avg=sum/n;
        count=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=avg)
                count++;
        }

        if(count==0)
        {
            printf("Exemplary pages.\n");
            continue;
        }

        if(count!=2)
        {
            printf("Unrecoverable configuration.\n");
            continue;
        }

        if(count==2)
        {
            j=-1;

            for(i=0;i<n;i++)
            {
                if(a[i]!=avg)
                {
                    t[++j]=a[i];
                    c[j]=i+1;
                }

            }

            if(t[0]<t[1])
                printf("%d ml. from cup #%d to cup #%d.\n", t[1]-avg,c[0], c[1]);
            else
                printf("%d ml. from cup #%d to cup #%d.\n", t[0]-avg,c[1], c[0]);
            continue;
        }


    }

}
