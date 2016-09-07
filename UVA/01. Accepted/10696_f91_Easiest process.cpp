#include<iostream.h>
main()
{
    int n;
    while(1)
    {
        int ans;
        cin>>n; if(n==0)    break;
        if(n>=101)
            ans=n-10;
        else
            ans=91;
        printf("f91(%d) = %d\n", n, ans);
    }
}
