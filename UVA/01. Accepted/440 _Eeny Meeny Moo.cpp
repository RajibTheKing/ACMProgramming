#include<stdio.h>
#include<string.h>

main()
{
    int a[160];
    int n, i, j, k, m, f;
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;

        for(m=1; ;m++)
        {
            j=0;
            f=0;
            memset(a, 0, sizeof(a));
            k=m-1;

            for(i=1; ;i++)
            {
                if(i>n) i=1;
                if(a[i]==1) continue;

                k++;
                if(k==m)
                {
                    j++;
                    k=0;
                    a[i]=1;

                }

                if(a[2]==1) break;

                if(j==n-1&&a[2]!=1)
                {
                    f=1;
                    break;
                }
            }

            if(f==1) break;
        }
        printf("%d\n", m);
    }

}
