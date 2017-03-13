#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;


bool check(string a, string b);

int main()
{
    string s[10005];
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i];

        sort(s, s+n);

        bool flag=false;

        for(int i=0;i<n-1;i++)
        {
            //cout<<s[i]<<"  "<<s[i+1]<<endl;
            flag=check(s[i], s[i+1]);

            if(flag==true) break;

        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;


    }


    return 0;
}

bool check(string a, string b)
{
    if(a.size()>b.size()) return false;

    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i]) return false;

    return true;
}

