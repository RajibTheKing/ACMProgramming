#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        bool flag=false;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='D')
                flag=true;
        }
        if(!flag)
            cout<<"Possible"<<endl;
        else
            cout<<"You shall not pass!"<<endl;


    }
}
