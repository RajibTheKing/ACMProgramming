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



int main()
{
    map<string, string> R;
    string s1="", s2="", s="";

    R.clear();
    char c;
    bool flag=false;
    int f=0;

    while(scanf("%c", &c)==1)
    {
        if(c=='\n'&&flag==false)
        {
            flag=true;
            f=2;
        }
        else if(c=='\n'&&flag==true)
            break;
        else if(c==' ')
        {
            f=1;
            continue;
        }
        else
            flag=false;

        if(f==0)
            s1+=c;
        else if(f==1)
            s2+=c;
        else if(f==2)
        {
            //cout<<s2<<" "<<s1<<endl;
            R[s2]=s1;
            f=0;
            s1="";
            s2="";
        }
        else
            continue;

    }

    while(cin>>s)
    {
        if(!R[s].empty())
            cout<<R[s]<<endl;
        else
            cout<<"eh"<<endl;
    }


    return 0;
}

