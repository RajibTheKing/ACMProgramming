#include<stdio.h>
int main()
{
    long long i, j, p, q, k, max=0, t, r;

    while (scanf("%lld %lld", &i, &k)==2)
    {
        max=0;
        p=i;
        q=k;

        if(i>k)
        {
            r=i;
            i=k;
            k=r;
        }




    //printf("%d  %d\n", i, k);

    for(i=i; i<=k; i++)
        {
            t=i;
            //printf("%d start\n", t);

            for(j=1; ; j++)
            {

                if(i==0)
                    break;


                else if(i==1)
                   break;

                else if(i%2==0)
                    i=i/2;

                else if(i%2!=0)
                        i=i*3+1;


                //printf("  %d\n", i);

            }

            if(max<j)
                max=j;
            if (t!=1)
                i=t;

        }

        printf("%lld %lld %lld\n", p, q, max);


    }
    return 0;
}
