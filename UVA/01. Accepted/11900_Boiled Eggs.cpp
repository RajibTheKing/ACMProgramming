#include<iostream.h>
main()
{
    int t, n, p, q, a[100];
    int i, j, w, count=0;

    cin>>t;
    while(t--)
    {
        cin>>n>>p>>q;
        for(i=0; i<n; i++)
            cin>>a[i];
        std::sort(a, a+n);
        j=0;
        w=0;
        for(i=0; i<n; i++)
        {
            w=w+a[i];
            if(p==j)
                break;

            if(w>q)
                break;

            j++;

        }

        printf("Case %d: %d\n", ++count, j);


    }
}
