#include<iostream.h>
#define max 30005

long long a[30005];

main()
{
    long long i, j, k;
    long long temp;

    double ammount;

    a[0]=1;
    for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+5;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

    for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+10;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

    for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+20;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

    for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+50;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+100;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+200;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+500;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+1000;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+2000;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+5000;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }

     for(i=0; i<max; i++)
    {
        if(a[0]!=0)
        {
            temp=i+10000;
            if(temp>max)
                break;
            a[temp]=a[temp]+a[i];
        }
    }





    while(1)
    {
        cin>>ammount;
        if(ammount==0)
            break;
        temp=( ammount*100+ 0.5);

        printf("%6.2lf%17lld\n",ammount, a[temp]);

    }


}
