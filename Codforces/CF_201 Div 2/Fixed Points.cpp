#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, t;
    vector<int> a;
    map<int, int> m;
    while(cin>>n)
    {
        a.clear();
        m.clear();
        for(int i=0;i<n;i++)
        {
            cin>>t;
            a.push_back(t);
            m[t]=i;
        }
        int kount=0;
        for(int i=0;i<n;i++) if(a[i]==i) kount++;
//        cout<<"Here: "<<kount<<endl;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(a[i]==i) continue;
            if(m[i]==a[i])
            {
                flag=true;
                break;
            }
        }
        if(flag) kount+=2;
        else kount+=1;
        kount = min(kount, n);
        cout<<kount<<endl;


    }

}
