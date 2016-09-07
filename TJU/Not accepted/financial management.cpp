#include<iostream.h>
main()
{
    float n, sum=0;
    int i=0;
    char c='$';
    while(scanf("%f", &n)==1)
    {
        i++;
        sum=sum+n;

        if(i==12)
        {
            printf("%c", c);
            printf("%0.2f\n", sum/12);
            i=0; sum=0;

        }

    }
}
