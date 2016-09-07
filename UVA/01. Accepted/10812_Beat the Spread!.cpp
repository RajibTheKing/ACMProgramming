#include<iostream.h>
main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long s, d, t1, t2, x, y;
        cin>>s>>d;
        x=s+d;
        y=s-d;
        t1=x/2;
        t2=y/2;


        if(d>s||(s%2)!=(d%2))
        {
            printf("impossible\n");
            continue;
        }
        else
            printf("%ld %ld\n", t1, t2);
    }
}
