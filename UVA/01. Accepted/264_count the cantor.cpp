#include<stdio.h>
#include<string.h>
#define size 100000

typedef struct node
{
    int a;
    int b;

};
node p[10009000];
void calculate(void);


main()
{
    calculate();
    int n;
    while(scanf("%d", &n)==1)
    {
        printf("TERM %d IS %d/%d\n", n, p[n].a, p[n].b);
    }

}






void calculate(void)
{
    int i, j, k, flag=0;
    k=0;
    p[++k].a=1;
    p[k].b=1;
    i=1;j=2;



    for(; ;)
    {
        if(flag==0)
        {
            for(; ;)
            {
                if(j==0)
                {
                    j=1;

                    flag=1;

                    break;
                }

                p[++k].a=i;
                p[k].b=j;

                i++;
                j--;

            }
        }

        if(flag==1)
        {
            for(; ;)
            {
                if(i==0)
                {
                    i=1;

                    flag=0;

                    break;
                }
                p[++k].a=i;
                p[k].b=j;

                i--;
                j++;
            }
        }

        if(k>10000000)
            break;
    }

}
