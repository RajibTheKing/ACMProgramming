#include<stdio.h>
#include<stdlib.h>
int summation(int b)
{
    int sum=0;
    while(b>=10)
    {
        sum+=b%10;
        b=b/10;
    }
    sum=sum+b;
    return sum;
}
int onedigit(int a)
{
    while(a>=10)
    {
        a=summation(a);
    }
    return a;
}

main()
{
    char c;
    int k=1, suma=0, sumb=0;
    float r;
    do{
        start:
        c=getchar();
        if(k==1)
        {
            if(c>='a'&&c<='z')
                suma+=c-96;
            else if(c>='A'&&c<='Z')
                suma+=c-64;
            else if(c=='\n')
            {
                k=-1;
                suma=onedigit(suma);
                goto start;
            }
        }
        if(k==-1)
        {
            if(c>='a'&&c<='z')
                sumb+=c-96;
            else if(c>='A'&&c<='Z')
                sumb+=c-64;
            else if(c=='\n'||c==EOF)
            {
                k=-1;
                sumb=onedigit(sumb);
                if(suma>sumb)
                    r=(float)sumb/suma;
                else
                    r=(float)suma/sumb;
                printf ("%.2f %%\n", r*100) ;

                k=1; suma=0; sumb=0;

            }

        }

     }while(c!=EOF);
}
