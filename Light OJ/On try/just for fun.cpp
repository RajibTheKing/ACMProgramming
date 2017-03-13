#include<iostream>
using namespace std;
int main()
{
    long long d=1010101;
    long long i=2;
    while(i<d)
    {
        if(d%i==0)
            cout<<i<<" x "<<d/i<<endl;
        i++;
    }
}
