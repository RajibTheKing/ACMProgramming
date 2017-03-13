#include<stdio.h>
#include<string.h>
#define size 10000000

int flag[10000500];
int prime[10000];
int a[3591];

int i, j, k;

void sieve(void)
{
    k=0;
    prime[++k]=2;
    for(i=3;i<size; i+=2)
    {
        if(flag[i]==0)
        {
            prime[++k]=i;
            for(j=i+i;j<size;j+=i)
                flag[j]=1;
        }
        if(k>3591) break;
    }
}

main()
{
    sieve();
    int n, t, p;
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;

        for(k=1;k<=n;k++)
            a[k]=1;

        p=1;
        for(i=1;i<n;i++)
        {
            t=prime[i];
            for(j=p; ;j++)
            {
                if(j>n) j=1;

                if(a[j]==0) continue;

                t--;
                if(t==0)
                {
                    a[j]=0;
                    p=j+1;
                    break;
                }
            }

        }
        for(i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                p=i;
                break;
            }
        }
        printf("%d\n", p);

    }
}
