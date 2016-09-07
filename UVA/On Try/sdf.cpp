#include<stdio.h>
main()
{
    int x=0;
    int i;
    for(i=1;i<10;++i)
    {
        if(i%2==0)
            x++;
        else
        {
            x--;
            break;
        }
        printf("%d ", x);
    }
    printf("\nx= %d", x);

}
