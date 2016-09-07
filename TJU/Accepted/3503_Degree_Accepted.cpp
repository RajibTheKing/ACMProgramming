#include<iostream.h>
#include<string.h>
int a[10001], b[10001];
main()
{
    int ca;
    cin>>ca;
    while(ca)
    {
        int i, n, max=0;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];
        for(i=0; i<n; i++)
            b[a[i]]++;
        for(i=0; i<10001; i++)
        {
            if(max<b[i])
                max=b[i];
        }
        printf("%d\n", max);
        memset(b, 0, 10001*sizeof(int));
        ca--;
    }
}
