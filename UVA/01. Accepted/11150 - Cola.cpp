#include<iostream.h>
main()
{
    int n, total, used, free;
    while(scanf("%d", &n)==1)
    {
        total=0;
        if(n==1)
        {
            total = n;
            cout<<total<<"\n";
            continue;
        }
        while(n>3)
        {
            used=(n/3)*3;
            free=n/3;
            total = total+used;
            n=n-used+free;
        }
        if(n==2||n==3)
            total = n+1+total;
        else
            total=total;
        cout<<total<<"\n";
    }

}
