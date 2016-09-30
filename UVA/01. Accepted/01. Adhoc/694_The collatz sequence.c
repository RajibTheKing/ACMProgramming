#include<stdio.h>
int main()
{
    long long i, j, p, q, l, max=0, t, r, ca=1;
    while (scanf("%lld %lld", &i, &l)==2)
    {
        if(i<0&&l<0)
            goto end;

        if(i>=0&&l>=0)
        {
            max=0;
            p=i;
            q=l;

            if(i>l)
            {
                r=i;
                i=l;
                l=r;
            }
            for(i=i; i<=l; i++)
            {
                for(j=1; ; j++)
                {
                    if(i==1||i==-1)
                        break;

                    else if(i%2==0)
                    {
                        i=i/2;
                        if(i>l)
                        break;
                    }

                    else if(i%2!=0)
                    {
                        i=i*3+1;
                        if(i>l)
                        break;
                    }
                }

                max=j;
                break;
            }

            printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", ca, p, q, max);
        }
        ca=ca+1;

    }
end:

    return 0;
}

