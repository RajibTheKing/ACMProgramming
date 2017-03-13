#include<iostream>
using namespace std;

int main()
{
    int n;
    int p1, p2, t;
    while(cin>>n)
    {
        p1=1;
        p2=n*n;
        t=n/2;
        for(int i=1;i<=n;i++)
        {
            int k=p1+t;
            for(p1;p1<k;p1++)
                cout<<p1<<" ";
            k=p2;
            for(p2=p2-t+1;p2<=k;p2++)
            {
                cout<<p2;
                if(p2<k) cout<<" ";

            }
            p2=p2-t-1;
            cout<<endl;
        }
    }
}
