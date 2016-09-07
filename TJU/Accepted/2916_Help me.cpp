#include<iostream.h>
double GCD(double a, double b);

main()
{

    double x,n, y, q;
    while(scanf("%lf %lf", &x, &y)==2)
    {
        n=GCD(x,y);
        n=(x/n)*y;
        n=n/x;
        cout<<int(n)<<endl;
    }
}

double GCD(double a, double b)
{

    double temp;
    if(a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }

    for(; ;)
    {
        temp=int(b)%int(a);
        if(temp==0)
            break;
        b=a;
        a=temp;
    }
    return a;
}

