#include<iostream.h>
long f91(long x);


main()
{
    while(1)
    {
        long n, ans;
        cin>>n;
        if(n==0)
            break;
        ans = f91(n);
        printf("f91(%ld) = %ld\n", n, ans);

    }

}

long f91(long x)
{
    long y;
    if(x>=101)
        return x-10;
    if(x<=100)
        x=f91(f91(x+11));
    return x;

}
