#include<iostream>
#include<string>
using namespace std;

int Onoroy_Value(long long n)
{
    int kount = 0;
    while(n)
    {
        if(n&1)
        {
            kount++;
        }
        n=n>>1;
    }
    return kount;
}
int main()
{

    int T, kase=0, qv, nv;
    long long n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        qv = Onoroy_Value(n);

        while(true)
        {
            if(qv==Onoroy_Value(++n))
            {
                cout<<"Case "<<++kase<<": "<<n<<endl;
                break;
            }
        }

    }
    return 0;
}
