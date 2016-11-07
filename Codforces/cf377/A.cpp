#include<bits/stdc++.h>

using namespace std;

int main()
{
    //cout<<"Hello world"<<endl;

    int k, r;
    while(cin>>k>>r)
    {
        int sum = 0;
        int i=0;
        while(true)
        {
            i++;
            sum = i*k;
            if(sum%10==0) break;
            if(sum==r) break;
            if((sum-r) % 10==0) break;


        }
        cout<<i<<endl;
    }

    return 0;
}
