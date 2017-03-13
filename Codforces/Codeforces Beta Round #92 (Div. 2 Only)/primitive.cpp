#include<iostream>
using namespace std;

main()
{
    int n, a, b;
    cin>>n>>a>>b;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=a+1&&n-i<=b)
            k++;
    }
    cout<<k<<endl;
}
