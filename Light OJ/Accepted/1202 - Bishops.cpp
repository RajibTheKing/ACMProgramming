#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long LL;

LL abss(LL a)
{
    if(a<0)
        return a * (-1);
    else return a;
}
int main()
{

    int T, kase=0;
    LL r1, r2, c1, c2;
    bool f1, f2;
    cin>>T;
    while(T--)
    {
        f1=false;


        cin>>r1>>c1>>r2>>c2;
        if(r1%2==1&&c1%2==1)
            f1=true;
        if(r1%2==0&&c1%2==0)
            f1=true;

        if(f1==true)
        {
            if(r2%2==1&&c2%2==0)
            {
                cout<<"Case "<<++kase<<": "<<"impossible"<<endl;
                continue;
            }

            if(r2%2==0&&c2%2==1)
            {
                cout<<"Case "<<++kase<<": "<<"impossible"<<endl;
                continue;
            }




        }
        else
        {
            if(r2%2==0&&c2%2==0)
            {
                cout<<"Case "<<++kase<<": "<<"impossible"<<endl;
                continue;
            }

            if(r2%2==1&&c2%2==1)
            {
                cout<<"Case "<<++kase<<": "<<"impossible"<<endl;
                continue;
            }

        }

        if(abss(r1-r2)==abss(c1-c2))
            cout<<"Case "<<++kase<<": "<<"1"<<endl;
        else
            cout<<"Case "<<++kase<<": "<<"2"<<endl;
    }
}
