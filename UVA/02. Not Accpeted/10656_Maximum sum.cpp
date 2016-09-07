#include<iostream.h>
main()
{
    int n;
    while(1)
    {
        int a[1005];
        cin>>n;
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n ; i++)
            cout<<a[i]<<" ";
        cout<<endl;

    }
}
