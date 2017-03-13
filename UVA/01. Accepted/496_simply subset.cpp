#include<stdio.h>
#include<string.h>
main()
{
    int t, k,i, j, n1, n2, flag;
    char c, a[1000];
    int A[100], B[100];
    memset(a, 0, sizeof(a));
    while(gets(a))
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        t=strlen(a);
        k=0;
        for(i=0;i<t;i++)
        {
           if(a[i]>='0'&&a[i]<='9')
           {
               if(a[i-1]==' ') k++;

                j=a[i]-'0'; A[k]=A[k]*10+j;
           }

        }
        n1=k+1;
        memset(a, 0, sizeof(a));
        gets(a);
        t=strlen(a);
        k=0;
        for(i=0;i<t;i++)
        {
           if(a[i]>='0'&&a[i]<='9')
           {
               if(a[i-1]==' ') k++;

                j=a[i]-'0'; B[k]=B[k]*10+j;
           }

        }

        n2=k+1;
        memset(a, 0, sizeof(a));
        int t=0;

        if(n1<n2)
            for(i=0;i<n1;i++)
            {
                for(j=0;j<n2;j++)
                {
                    if(A[i]==B[j])
                        t++;
                }
            }
        else
            for(i=0;i<n2;i++)
            {
                for(j=0;j<n1;j++)
                {
                    if(B[i]==A[j])
                        t++;
                }
            }

        if(n1==n2&&t==n1)
            printf("A equals B\n");

        else if(n1>n2&&t==n2)
            printf("B is a proper subset of A\n");

        else if(n1<n2&&t==n1)
            printf("A is a proper subset of B\n");

        else if(t==0)
            printf("A and B are disjoint\n");

        else
            printf("I'm confused!\n");

    }
}

