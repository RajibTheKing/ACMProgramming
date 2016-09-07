#include<stdio.h>
#include<string.h>


typedef struct node
{
    int a;
    int b;

};

main()
{

    int i, j, k, flag=0;
    node p[100900];


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
                    //i++;
                    flag=1;

                    break;
                }

                p[++k].a=i;
                p[k].b=j;
                printf("%d: %d/%d\n", k, p[k].a, p[k].b);
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
                    //j++;
                    flag=0;

                    break;
                }
                p[++k].a=i;
                p[k].b=j;
                printf("%d: %d/%d\n", k, p[k].a, p[k].b);
                i--;
                j++;
            }
        }


        if(k>10000000)
            break;
    }


}
