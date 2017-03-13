#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;
main()
{
    int s1=0, s2=0;

    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='4') s1++;
        if(a[i]=='7') s2++;
    }
    if(s1==0&&s2==0)
        cout<<"-1"<<endl;
    else if(s1>=s2)
        cout<<"4"<<endl;
    else
        cout<<"7"<<endl;
}
