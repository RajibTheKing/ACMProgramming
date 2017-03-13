#include<stdio.h>
#include<math.h>
#define EPS (1e-9)

bool dp[10005];

int  check(long  n)
{
    int  k, i;
    k=sqrt(n);
    for(i=2;i<=k;i++)
    {
        if((n%i)==0) return 0;
    }
    return 1;
}

void calculate(void)
{
    long  i, num, f;
    for(i=0;i<=10001;i++)
    {
        num=i*i+i+41;
        dp[i] = check(num);
    }
}

main()
{

    calculate();
    float ans, count;
    long  a, b, i, t;
    while(scanf("%ld %ld", &a, &b)==2)
    {
        t=b-a+1;
        count=0;
        for(i=a;i<=b;i++)
        {
            count=count+dp[i];
        }

        ans=count/t*100;

        printf("%.2f\n",ans + EPS);
    }
}
