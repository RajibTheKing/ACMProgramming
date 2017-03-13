#include<bits/stdc++.h>

using namespace std;
#define SZ 505

int arr[SZ];
int brr[SZ];
int main()
{
    //cout<<"Hello world"<<endl;

    int n, k;
    while(cin>>n>>k)
    {
        int sum1=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum1+=arr[i];
        }

        int sum2=0;
        brr[0]=arr[0];
        sum2+=brr[0];
        for(int i=1;i<n;i++)
        {
            brr[i] = max(k-brr[i-1], arr[i]);
            sum2+=brr[i];

        }
        cout<<sum2-sum1<<endl;
        for(int i=0;i<n;i++)
        {
            if(i)cout<<" ";
            cout<<brr[i];
        }
        cout<<endl;

    }

    return 0;
}

