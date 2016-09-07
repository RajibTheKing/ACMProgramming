#include<iostream.h>

int a[500];
int n, m;
int i, j, k;
int gcd, lcm;

int  function(int p , int q)
{
    int t;

    if(p==0)
        return q;
    if(q==0)
        return p;

    if(p>q)
    {
        t=p;
        p=q;
        q=t;
    }

    for(; ;)
    {

        gcd=q%p;
        if(gcd==0)
            break;
        q=p;
        p=gcd;
    }

    return p;
}


main()
{
    int p, q;
    cin>>n;
    while(n--)
    {
        cin>>m;
        gcd=a[0];
        for(i=0; i<m; i++)
            cin>>a[i];
        std::sort(a, a+m);
        lcm=a[0];

        for(i=1; i<m; i++)
        {
            q=a[i];
            if(q==0)
            {
                lcm=0;
                break;
            }
            gcd=function(lcm, q);
            lcm=(lcm*q)/gcd;
        }

        printf("%d\n", lcm);
    }
}
