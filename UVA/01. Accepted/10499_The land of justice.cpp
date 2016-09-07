#include<iostream.h>
main()
{
    char c='%';
    long long n;
    while(1)
    {
        cin>>n;
        if(n<0) break;
        if(n==1)
            printf("0%c\n",c );
        else
            printf("%lld%c\n", n*25, c);
    }
}
