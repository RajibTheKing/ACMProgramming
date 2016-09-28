#include<iostream>
using namespace std;
#define SZ 10000

int main()
{
    long long arr[20];
    long long num = 1;
    for(int i=0;i<20;i++)
    {
        arr[i] = num;
        num*=10;
        num+=1;
    }

    for(int i=0;i<=100;i++)
    {
        cout<<"For "<<i<<": ";
        int ans = -1;
        for(int j=0;j<20;j++)
        {
            if(arr[j]%i==0)
            {
                ans = j;
                break;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
