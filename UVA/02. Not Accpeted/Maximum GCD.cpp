#include<iostream.h>
#include<string.h>
long a[101];
long x, y, max=0, GCD, h;
int main()
{
    int n;
    scanf("%d", &n);
    while(n)
    {
        char c;
        int i=-1, j, k, t, temp;
        for(; ;)
        {
            scanf("%ld%c", &a[++i], &c);
            if(c=='\n')
                break;
        }
        for(j=0; j<=i; j++)
        {
            x=a[j];
            t=j;
            h=x;
            for(k=0;k<=i; k++)
            {
                if(k==t)
                    continue;
                y=a[k];

                if(x<max||y<max)
                    continue;
                if(x<y)
                {
                    temp=x;
                    x=y;
                    y=temp;
                }

                for(; ;)
                {
                    GCD=x%y;

                    if(GCD==0)
                    {
                        GCD=y;
                        break;
                    }
                    x=y;
                    y=GCD;

                }
                if(max<GCD)
                    max=GCD;

                x=h;
            }
        }
        printf("%ld\n", max);
        max=0;

        memset(a, 0, 101*sizeof(long));
        n--;
    }
    return 0;
}
