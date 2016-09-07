#include<iostream>
using namespace std;

main()
{
    long long fibonacci[60];
    int i, t, n, kase=0;
    fibonacci[1]=2;
    fibonacci[2]=3;
    for(i=3;i<=60;i++)
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];

    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Scenario #"<<++kase<<":"<<endl;
        cout<<fibonacci[n]<<endl;
        cout<<endl;
    }

}
