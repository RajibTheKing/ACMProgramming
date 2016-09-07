#include<stdio.h>

int a[1001][1011];
int b[1011][1011];

int Combinations(unsigned int n, unsigned int k)
{
    int p, q;
    p=n-k;q=k;
    if(b[n-k][k]!=0)
        return b[n][k];

     if (k > n)
         return 0;
     int r = 1;
     for (unsigned int d = 1; d <= k; ++d)
     {
         r *= n--;
         r /= d;
     }
     b[p][q]=r;
     return r;
}

main()
{
    int n, m, ans, i, j;
    for(i=1;i<=1000;i++)
    {
        for(j=1;j<=1000;j++)
            a[i][j]=Combinations(i+j, j);
    }

    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0&&m==0)
            break;
        printf("%d\n", a[n][m]);
    }
}

