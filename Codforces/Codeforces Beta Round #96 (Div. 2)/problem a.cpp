#include<iostream>
#include<string.h>


using namespace std;
bool flag[150];

int main()
{
    string a;
    string b = "HQ9+";

    int temp;
    temp = 'H';
    flag[temp]=true;
    temp='Q';
    flag[temp]=true;
    temp = '9';
    flag[temp]=true;



    while(cin>>a)
    {

    bool f;
    f=false;

    for(int i=0;i<a.length();i++)
    {
         temp=a[i];

        if(flag[temp]==true)
        {
            f=true;
            break;
        }
    }

    if(f==true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
    return 0;
}
