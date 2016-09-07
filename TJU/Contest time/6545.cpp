#include<iostream>
#include<string>
#include<vector>
using namespace std;
main()
{
    string a[200];
    string b;
    int n;
    char c;
    cin>>n;
    {

        for(int i=0;i<n;i++)
        {
            cin>>b;
            a[i]="";
            a[i]+=b;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a[i].length();j++)
            {
                int t;
                char d;
                t=a[i][j];
                t++;
                if(t>90)
                    t=t-26;
                d=t;
                printf("%c", d);
            }
            cout<<endl;
        }

    }
}
