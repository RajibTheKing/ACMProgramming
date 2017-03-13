#include<iostream>
using namespace std;
main()
{
    int T, x, y, z;
    int ans;
    cin>>T;
    while(T--)
    {
        cin>>x>>y>>z;
        ans = z*(x+(x-y))/(x+y) ;
        cout<<ans<<endl;

    }
}
