#include<iostream.h>
#include<string.h>

 long a[20], b[20], c[20], d[20];

main()
{

    long m, n, i, j, k, l, t, temp;
    long operation, h;
    while(1)
    {
        cin>>m;
        cin>>n;

        if(m==0&&n==0)
            break;

        if(m<n)
        {
            temp=m;
            m=n;
            n=temp;
        }

        for(i=0; ; i++)
        {
            c[i]=m%10;
            m=m/10;
            if(m==0)
                break;
        }
        k=i+1;


        for(i=0; ; i++)
        {
            d[i]=n%10;
            n=n/10;
            if(n==0)
                break;
        }

        l=i+1;

        if(k>l)
            t=k;
        else
            t=l;



        j=t;
        for(i=0; i<k; i++)
            a[--j]=c[i];


        j=t;
        for(i=0; i<l; i++)
            b[--j]=d[i];



        operation=0;
        h=0;

        for(i=t-1; i>=0; i--)
        {
            k=a[i]; l=b[i];
            j=k+l+h;
            if(j>=10)
            {

                operation=operation+1;
                h=1;
            }
            else
                h=0;
        }


        if(operation==1)
            printf("%d carry operation.\n", operation);
        else if(operation>1)
            printf("%d carry operations.\n", operation);
        else
            printf("No carry operation.\n");

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));


    }
}
