#include<iostream.h>

#define max 1000000001


bool a[max];
main()
{
    int i, j, k, l;
    for(i=2, j=1; i<=max; i++)
    {
        if(a[i]!=0)
            continue;

        for(j=i; j<=max; j=j+i)
            a[j]++;
    }


    for(i=2; i<10; i++)
        cout<<a[i]<<" ";
}

