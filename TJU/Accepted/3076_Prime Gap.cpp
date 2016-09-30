#include<stdio.h>
#define sz 1900000
int prime[100005];
bool flag[10000005];

void sieve(void)
{
    int i, j, k;
    k=0; flag[0]=1;flag[1]=1;
    for(i=2;i<=sz;i++)
    {
        if(flag[i]==0)
        {
            prime[++k]=i;
            for(j=i+i;j<=sz;j+=i)
            {
                flag[j]=1;
            }
        }
        if(k==100001) break;
    }


}

main()
{
    sieve();
    int n, t1, t2, i, j;

    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;
        if(flag[n]==0) printf("%d\n", flag[n]);
        else
        {
            for(i=n-1;;i--)
                if(flag[i]==0) break;
            t1=i;
            for(i=n+1;;i++)
                if(flag[i]==0) break;
            t2=i;

            printf("%d\n", t2-t1);
        }
    }

}
