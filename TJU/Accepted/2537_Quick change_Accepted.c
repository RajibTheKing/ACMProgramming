#include<stdio.h>
int main()
{

    int a[1000];
    int i, q, d, n, p, count=0, ss;

    scanf("%d", &ss);
    for(i=0; i<ss; i++)
        scanf("%d", &a[i]);
    for(i=0;i<ss ;i++ )
    {
        count++;
        for(; ;)
        {
            q=d=n=p=0;
            if(a[i]>=25)
            {
                q=a[i]/25;
                a[i]=a[i]%25;


            }
            if(a[i]>=10)
            {
                d=a[i]/10;
                a[i]=a[i]%10;

            }
            if(a[i]>=5)
            {
                n=a[i]/5;
                a[i]=a[i]%5;

            }
            if(a[i]>=1)
            {
                p=a[i]/1;
                a[i]=a[i]%1;

            }
            if(a[i]==0)
                break;
        }
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", count, q, d, n, p);


    }



    return 0;
}

