
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
#define mod 1000000007

bool isVowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    return false;
}
bool check(string s)
{
    int l = s.length();
    bool flag;
    flag=false;
    for(int i=0;i<l;i++)
        if(isVowel(s[i]))
        {
            flag=true;
            break;
        }
    if(flag==false) return false;
    int t1, t2;
    t1=0;
    t2=0;
    flag=false;
    for(int i=0;i<l;i++)
    {
        if(isVowel(s[i]))
        {
            t2=0;
            t1++;
        }
        else
        {
            t1=0;
            t2++;
        }
        if(t1==3||t2==3)
            flag=true;



    }
    if(flag) return false;

    for(int i=1;i<l;i++)
        if(s[i]==s[i-1])
        {
            if(s[i]=='e'||s[i]=='o') continue;

            return false;
        }
    return true;
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="end") break;
        cout<<"<"<<s<<">";

        if(check(s))
            cout<<" is acceptable."<<endl;
        else
            cout<<" is not acceptable."<<endl;





    }


    return 0;
}


