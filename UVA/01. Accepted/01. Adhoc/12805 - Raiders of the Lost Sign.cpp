#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    int t;
    int kase = 0;

    while(cin>>t)
    {
        int knt = 0;
        for(int i=0;i<t;i++)
        {
            cin>>str;
            if(isValid(str))
                knt++;


        }
        printf("Case %d: %d\n", ++kase, knt);
    }
    return 0;
}

