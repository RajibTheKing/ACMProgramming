#include<iostream>
using namespace std;

bool check(int a)
{
   // cout<<a<<": ";
    int sum=0;
    while(a)
    {
        sum+=a%10;
        a/=10;
    }
    //cout<<sum<<endl;
    if(sum%10) return false;
    return true;
}

int main()
{
    int t,n;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            n++;
            while(true)
            {
                if(check(n))
                {
                    cout<<n<<endl;
                    break;
                }
                n++;
            }
        }
    }
    return 0;
}
