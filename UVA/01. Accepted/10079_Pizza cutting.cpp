#include<iostream.h>
main()
{
    while(1)
    {
        long a;
        scanf("%ld", &a);
        if(a<0)
            break;
        printf("%ld\n", (a*(a+1))/2+1);
    }
}
