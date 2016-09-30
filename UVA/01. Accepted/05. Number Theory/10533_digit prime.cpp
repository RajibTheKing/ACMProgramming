
#include<stdio.h>
#define size 1000000
bool flag[size+50];
int digit_prime[size+10];

void seive(void)
{
    int i, j;
    for(i=2;i<=size;i++)
    {
        if(flag[i]==0)
        {
            for(j=i+i;j<=size;j+=i)
                flag[j]=1;
        }
    }

}
int sum(int a)
{
    int i=0;
    for(; ;)
    {
        i=i+a%10;
        a=a/10;
        if(a<=0)
            break;
    }
    return i;
}

void calculate(void)
{
    int i, j, k, l=0;
    for(i=2;i<=size;i++)
    {
        if(flag[i]==0)
        {
            k=sum(i);
            if(flag[k]==0)
               l++;
        }
        digit_prime[i]=l;
    }

}

main()
{
    int i, n, t1, t2, ans;

    seive();
    calculate();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &t1, &t2);
        ans=digit_prime[t2]-digit_prime[t1-1];
        printf("%d\n", ans);
    }

}
