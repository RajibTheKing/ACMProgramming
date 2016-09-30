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

bool check(string s)
{
    int t = s.length();
    if(s[t-1]=='o'||s[t-1]=='s'||(s[t-2]=='c'&&s[t-1]=='h')||(s[t-2]=='s'&&s[t-1]=='h')||s[t-1]=='x')
        return true;
    return false;
}
bool isConsonant(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return false;
    return true;
}
int main()
{
    map<string, string> R;
    string s1="", s2="", s="";
    R.clear();
    int L, N, t;
    while(cin>>L>>N)
    {
        for(int i=0;i<L;i++)
        {
            cin>>s1>>s2;
            R[s1]=s2;
        }

        for(int i=0;i<N;i++)
        {
            cin>>s;
            t=s.length();

            if(!R[s].empty())
                cout<<R[s]<<endl;
            else if(s[t-1]=='y' && isConsonant(s[t-2])==true)
            {
                s[t-1]='i';
                s+="es";
                cout<<s<<endl;
            }
            else if(check(s)==true)
                cout<<s<<"es"<<endl;
            else
                cout<<s<<"s"<<endl;

        }

        R.clear();
    }



    return 0;
}

