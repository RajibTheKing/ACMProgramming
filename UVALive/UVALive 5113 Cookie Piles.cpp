
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, a, d;
        cin>>n>>a>>d;
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=a+ (d*i);
        cout<<ans<<endl;
    }
}
