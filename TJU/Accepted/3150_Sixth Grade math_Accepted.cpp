#include<stdio.h>
#include<iostream.h>
int main()
{

    int a[1005], b[1005], n, temp;
    int i, j, k, l, m, o, count=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for(i=0; i<n; i++)
    {
        count++;
        l=a[i];
        m=b[i];
        if(a[i]>b[i])
        {
            temp=a[i];
            a[i]=b[i];
            b[i]=temp;
        }


        for(j=0; ;j++)
        {
            if(b[i]%a[i]==0)
                break;
            k=b[i]%a[i];
            b[i]=a[i];
            a[i]=k;

        }
        o=(l*m)/a[i];
        printf("%d %d %d\n", count, o, a[i]);


    }
    return 0;

}
