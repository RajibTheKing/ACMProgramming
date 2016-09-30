#include<iostream.h>
main()
{
    double t, n, a, b, c, sum, p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        while(n--)
        {
             scanf("%lf", &a); scanf("%lf", &b); scanf("%lf", &c);
             p=a/b;
             p=p*c;
             p=p*b;
             sum=sum+p;

        }
        printf("%d\n", int(sum));

    }
}
