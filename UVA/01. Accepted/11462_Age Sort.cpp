#include<iostream.h>
int a[2000005];

main()
{

    int n, i;
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);

        std::sort(a, a+n);
        for(i=0; i<n; i++)
        {
            printf("%d", a[i]);
            if(i+1==n)
            {
                printf("\n");
                break;
            }
            printf(" ");
        }

    }
}
