#include<iostream>
using namespace std;
int main()
{
    int n;
    int t, i, sum, a[500];
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i]-1;
        }
        cout<<sum+1<<endl;
    }
    return 0;
}
