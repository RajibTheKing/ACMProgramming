#include<iostream.h>
main()
{
    long long x, sum;
    while(scanf("%lld", &x)==1)
    {
        sum=(x*(x+1))/2;
        sum=sum*sum;
        cout<<sum<<endl;
    }
}
