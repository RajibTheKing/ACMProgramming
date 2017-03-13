#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    long long T;
    long long n,m;
    long long kase=0;
    cin>>T;

    while(T--)
    {
        cin>>n>>m;

        cout<<"Case "<<++kase<<": "<<n*m/2<<endl;
    }
}
