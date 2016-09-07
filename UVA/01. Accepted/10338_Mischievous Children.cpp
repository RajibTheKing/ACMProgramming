#include<iostream.h>
#include<string.h>

long long factorial(long long n)
{
    if(n<1)
        return 1;
    else
        return n*factorial(n-1);
}

main()
{
    char b[25], c[10];;
    long long a[27];
    long long t, k, j, ans, count=0;
    gets(c);
    t=atoi(c);

    while(t--)
    {
        count++;
        memset(b, 0, sizeof(b));
        memset(a , 0, sizeof(a));
        gets(b);
        k=strlen(b);
        for(int i=0; i<=k; i++)
        {
            j=b[i]-'A';
            a[j]++;
        }

        ans=factorial(k);

        for(int i=0; i<27;i++)
        {
            if(a[i]>1)
            ans=ans/factorial(a[i]);
        }


        printf("Data set %lld: %lld\n", count, ans);
    }
}
