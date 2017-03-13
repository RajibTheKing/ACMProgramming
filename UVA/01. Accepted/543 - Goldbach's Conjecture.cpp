#include<stdio.h>
#define sz 1000300
bool flag[2000100];

int prime[100000];

void sieve()
{
    int k=-1, i, j;
    flag[0]=true;
    flag[1]=true;
    for(i=2;i<sz;i++)
    {

        if(flag[i]==false)
        {
            prime[++k]=i;
            for(j=i+i;j<sz;j+=i)
                flag[j]=true;
        }

    }
}

main()
{
    sieve();
    int n;
    int i,j, f, p, q;
    while(scanf("%d", &n)==1)
    {
        if(n==0) break;
        f=0;
        for(i=0;;i++)
        {
            p=prime[i];
            if(p>n) break;
            q=n-p;
            if(flag[q]==false)
            {
                f=1;
                break;
            }
        }
        if(f==1)
            printf("%d = %d + %d\n", n, p, q);
        else
            printf("Goldbach's conjecture is wrong.\n");

    }

}
