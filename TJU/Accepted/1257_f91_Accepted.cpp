#include<iostream.h>

long f91(long a);

int main()
{
    while (1)
    {
        long n, t;
        cin>>n;
        if(n==0)
            goto end;
        t = f91(n);

        printf("f91(%ld) = %ld\n", n, t);
    }
end:

    return 0;
}
long f91(long a)
{
    if(a<=100)
        return f91(f91(a+11));
    if(a>=101)
        return (a-10);
}

