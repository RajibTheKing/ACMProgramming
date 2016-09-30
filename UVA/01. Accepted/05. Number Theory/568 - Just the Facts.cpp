#include<iostream.h>
int main()
{
    long long i, n, product;
    while(scanf("%lld", &n)==1)
    {
        if(n>1)
        {
            product=1;
            for(i=2; i<=n; i++)
            {
                product=product*i;
                for(; ;)
                {
                    if(product%10==0)
                        product=product/10;
                    else
                        break;
                }

                product=product%1000000;


            }


            printf("%5lld -> %lld\n", n, product%10);


        }
        else
        {
                product = 1;
                printf("%5lld -> %lld\n", n, product);
        }




    }


    return 0;
}
