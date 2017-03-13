#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    vector<string> a, b, c;
    string p, q;
    int n;
    while(cin>>n)
    {
        a.clear();
        b.clear();
        for(int i=0;i<n;i++)
        {
            cin>>p>>q;
            a.push_back(p);
            b.push_back(q);
        }

        cout<<n<<": "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }
        cout<<endl;

    }

    return 0;
}
