#include<iostream.h>
int a[101], b[60], c[60];;
int main()
{

    int n, temp, flag, j, sum1=0, sum2=0, min=45001, f, k, t, psum1, psum2;
    cin>>n;
    int i;
    for(i=0; i<n; i++)
        cin>>a[i];
    if(n%2!=0)
    {
        temp=n/2+1;
        flag=1;
    }
    else
    {
        temp=n/2;
        flag=0;
    }
    std::sort(a, a+n);
    for(i=0; i<temp; i++)
        b[i]=a[i];
    for(i=temp, j=0;i<n; i++, j++)
        c[j]=a[i];


    for(i=0; i<temp; i++)
        sum1=sum1+b[i];
    for(i=0; i<j; i++)
        sum2=sum2+c[i];
    psum1=sum1;
    psum2=sum2;
    if(sum2==sum1)
    {
        printf("%d %d\n", sum1, sum2);
        goto end;
    }
    sum1=0;
    sum2=0;
    for(; ; )
    {
        for(k=0; k<j; k++)
        {
            f=0;
            for(i=0; i<temp; i++)
            {
                if(c[k]>b[i])
                {
                    t=c[k];
                    c[k]=b[i];
                    b[i]=t;
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
        }
        for(i=0; i<temp; i++)
            sum1=sum1+b[i];
        for(i=0; i<j; i++)
            sum2=sum2+c[i];
        if(sum2-sum1==1)
        {
            printf("%d %d\n", sum1, sum2);
            goto end;
        }
        if(sum2<sum1)
        {
            printf("%d %d\n", psum1, psum2);
            goto end;
        }
        if(sum2==sum1)
        {
            printf("%d %d\n", sum1, sum2);
            goto end;
        }

        psum1=sum1;
        psum2=sum2;
        sum1=0;
        sum2=0;

    }


end:


    return 0;
}
