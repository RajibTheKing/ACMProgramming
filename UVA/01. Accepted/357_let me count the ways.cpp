#include<iostream.h>
#define max 30005

main()

{
    long long a[30005];
    long long i, j, temp;

    memset(a, 0, sizeof(a));
    a[0]=1;

    for(i=0; i<max; i++)
    {
        if(a[i]!=0)
        {
            temp=i+1;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

    for(i=0; i<max; i++)
    {
        if(a[i]!=0)
        {
            temp=i+5;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[i]!=0)
        {
            temp=i+10;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[i]!=0)
        {
            temp=i+25;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[i]!=0)
        {
            temp=i+50;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }



    long long ammount;

    while(scanf("%lld", &ammount)==1)
    {
        if(a[ammount]>1)
            printf("There are %lld ways to produce %lld cents change.\n", a[ammount], ammount);
        else
            printf("There is only %lld way to produce %lld cents change.\n", a[ammount], ammount);
    }
}
