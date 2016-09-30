#include<iostream.h>
#include<math.h>
main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n=n*567;
        n=n/9;
        n=n+7492;
        n=n*235;
        n=n/47;
        n=n-498;
        n=abs((n%100)/10);

        cout<<n<<endl;
    }
}
