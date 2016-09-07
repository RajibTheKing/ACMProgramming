#include<iostream.h>
int main()
{
    long n, t, res, temp, half;
    scanf("%ld", &t);
    while(t)
    {
        scanf("%ld", &n);
        half=n/2;
        res=0;
        for(int i=1; i<=n; i++)
        {
            temp=n/i;
            printf("%d  %d\n", res, temp);
            res=res+temp;

            if(i==half)
            {
                res=res+n-half;
                break;
            }
        }
        printf("%ld\n", res);
        t--;
    }
    return 0;
}

