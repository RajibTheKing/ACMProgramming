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

char a[130];
void initialize()
{
    for(int i=0;i<128;i++)
        a[i]=i;

}

int main()
{
    string s1, s2, s;

    while(getline(cin, s1))
    {
        getline(cin, s2);
        initialize();
        for(int i=0;i<s1.length();i++)
        {
            a[s1[i]]=s2[i];
            //a[s2[i]]=s1[i];
        }

        cout<<s2<<endl;
        cout<<s1<<endl;
        while(getline(cin, s))
        {
            for(int i=0;i<s.length() ;i++)
            {
                int temp=s[i];
                printf("%c", a[temp]);
            }
            if(s.length()>0)
                cout<<endl;


        }

        return 0;
    }
}

