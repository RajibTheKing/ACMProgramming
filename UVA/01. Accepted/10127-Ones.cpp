#include<iostream>
using namespace std;
#define SZ 10000

int main()
{
    long long num;
    while(cin>>num)
    {
        long long value = 1;
        long long ans = 1;
        while(true)
        {
            if(value%num==0) break;

            value = value%num;
            value = value*10 + 1;
            ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
