#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long n;
    while(cin>>n)
    {
        while(n%3==0)
            n/=3;
        n/=3;
        n++;
        cout<<n<<endl;
    }

}
