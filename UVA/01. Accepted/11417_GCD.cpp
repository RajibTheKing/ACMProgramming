#include<stdio.h>

int ans[550][550];

void memorise(int i, int j)
{
    int temp, m, a, b;
    a=i;b=j;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }

    m=b%a;
    for(; ;)
    {
        if(a%m==0) break;
        b=a;
        a=m;
        m=b%a;
    }
    ans[i][j]=m;

}

int GCD(int i, int j)
{
    return ans[i][j];
}

main()
{
    int G, N, i, j;

    for(i=1;i<520;i++ )
        for(j=i+1;j<=520;j++)
            memorise(i,j);

    while(scanf("%d", &N)==1)
    {
        if(N==0) break;

        G=0;
        for(i=1;i<N;i++)
            for(j=i+1;j<=N;j++)
                G+=GCD(i,j);
        printf("%d\n", G);
    }
}
