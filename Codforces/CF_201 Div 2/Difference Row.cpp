#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    int n, t;
    while(cin>>n)
    {
        a.clear();

        for(int i=0;i<n;i++)
        {
            cin>>t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        t=a[0];
        a[0]=a[a.size()-1];
        a[a.size()-1]=t;
        for(int i=0;i<a.size();i++)
        {
            if(i==0)
                cout<<a[i];
            else
                cout<<" "<<a[i];
        }
        cout<<endl;

    }

    return 0;
}
