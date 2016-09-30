#include<iostream.h>
main()
{
    int t, n, a[105], i, s, cs=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];

        s=0;
        for(i=0; i<n; i++)
            if(s<a[i])  s=a[i];

        printf("Case %d: %d\n", ++cs, s);
    }
}
