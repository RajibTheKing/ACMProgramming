#include<iostream>
#include<string>
using namespace std;

int main()
{

    int T, kase=0, account=0, n, money;
    cin>>T;
    string s;

    while(T--)
    {
        account=0;
        cin>>n;
        cout<<"Case "<<++kase<<":"<<endl;
        while(n--)
        {
            cin>>s;
            if(s=="donate")
            {
                cin>>money;
                account+=money;
            }
            else
                cout<<account<<endl;
        }

    }
    return 0;
}
