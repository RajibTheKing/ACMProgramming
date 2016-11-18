#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    while(cin>>n)
    {
        cin>>str;
        int k1 = 0, k2 = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='A')
                k1++;
            else
                k2++;

        }

        if(k1==k2)
            cout<<"Friendship"<<endl;
        else if(k1>k2)
            cout<<"Anton"<<endl;
        else
            cout<<"Danik"<<endl;

    }
}
