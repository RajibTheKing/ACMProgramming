#include<stdio.h>

main()
{
    int a[10000];
    int n, i,j, p, q, temp;
    while(1)
    {

        scanf("%d", &n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d" , &a[i]);

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                if(a[j]>a[i])
                {
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
        }

        p=a[0];
        q=p;

        for(i=1;i<n;i++)
        {

            if(a[i]<p)
            {
                q=a[i];
                break;
            }
        }
        printf("%d\n", q);

    }
}
