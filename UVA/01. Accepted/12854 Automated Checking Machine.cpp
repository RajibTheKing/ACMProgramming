#include <stdio.h>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    string str1, str2;

    while(getline(cin, str1))
    {
        getline(cin, str2);

        stringstream ss1, ss2;
        ss1.clear();
        ss2.clear();
        ss1<<str1;
        ss2<<str2;
        int a1, a2;

        bool flag = true;
        while(ss1>>a1)
        {
            ss2>>a2;
            int temp = a1^a2;

           // cout<<a1<<", "<<a2<<", "<<temp<<endl;

            if(!temp)
            {
                flag = false;
                break;
            }

        }
        if(flag)
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }

    }
    return 0;
}
