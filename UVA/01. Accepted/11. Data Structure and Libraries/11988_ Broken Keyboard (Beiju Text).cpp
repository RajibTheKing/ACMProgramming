#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<sstream>
#include<deque>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s,temp;
    char a[109999];
    int i, StringLength;

    while(gets(a) != NULL)
    {
        StringLength=strlen(a);
        deque<string> d;
        temp="";
        bool cursor=false;
        for(i=0;i<StringLength;i++)
        {
            if(a[i]=='[')
            {
                if(cursor==true)
                    d.push_front(temp);
                else
                    d.push_back(temp);
                temp="";
                cursor=true;
                continue;
            }
            if(a[i]==']')
            {
                if(cursor==true)
                    d.push_front(temp);
                else
                    d.push_back(temp);
                temp="";
                cursor=false;
                continue;
            }
            temp.push_back(a[i]);
        }

        if(temp!="")
        {
            if(cursor==true)
                d.push_front(temp);
            else
                d.push_back(temp);

        }

        while(!d.empty())
        {
            printf("%s", d.front().c_str());
            d.pop_front();
        }
        printf("\n");

    }
}
