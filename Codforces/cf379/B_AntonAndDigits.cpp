#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k2,k3,k5,k6;
    while(cin>>k2>>k3>>k5>>k6)
    {
        int first = min(k2,min(k5,k6));
        k2-=first;
        int second = min(k2,k3);

        cout<<first*256+second*32<<endl;

    }
}

