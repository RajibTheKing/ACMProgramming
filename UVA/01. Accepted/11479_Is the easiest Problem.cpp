#include<iostream.h>
main()
{
    long long t, x;
    long long a[4];
    cin>>t;
    x=0;
    while(t--)
    {
        cin>>a[0]>>a[1]>>a[2];
        std::sort(a, a+3);


        if((a[0]+a[1])>a[2])
        {
            if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[0])
                printf("Case %lld: Equilateral\n", ++x);
            else if(a[0]==a[1]||a[1]==a[2]||a[2]==a[0])
                printf("Case %lld: Isosceles\n", ++x);
            else
                printf("Case %lld: Scalene\n", ++x);
        }
        else
            printf("Case %lld: Invalid\n", ++x);

    }
}
