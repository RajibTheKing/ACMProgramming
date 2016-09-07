#include<iostream.h>
main()
{
    int n, a, t, j, flag=0;
    while(scanf("%d", &n)==1)
    {

        cin>>a;
        j=n*n;
        t=a;
        flag=0;
        for(; ;)
        {

            if(t>j)
                break;

            if(flag==1)
                printf(" ");
            printf("%d", t);
            if(t%n==0)
                break;
            t=t+n+1;
            flag=1;
        }

        printf("\n");
    }
}
