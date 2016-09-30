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


int number(string s)
{
    stringstream ss;
    ss.clear();
    int n;
    ss<<s;
    ss>>n;
    return n;
}
bool check(int n)
{
    if(n>=65&&n<=90) return true;
    else if(n>=97&&n<=122) return true;
    else if(n==32||n==33||n==44||n==46||n==58||n==59||n==63) return true;
    else return false;

}
int main()
{
    char c[2000];
    int num;
    while(gets(c))
    {

        if(c[0]>='0'&&c[0]<='9')
        {
            reverse(c, c+strlen(c));
            string s="";
            for(int i=0;i<strlen(c);i++)
            {
                s+=c[i];
                num=number(s);
                if(check(num))
                {
                    s="";
                    printf("%c", num);
                }
            }
        }
        else
        {
            string t="", f;
            for(int i=0;i<strlen(c);i++)
            {
                num=(int) c[i];
                stringstream ss;
                ss.clear();
                ss<<num;
                f="";
                ss>>f;
                t+=f;
            }

            for(int i=t.length()-1;i>=0;i--)
                printf("%c", t[i]);

        }

        cout<<endl;

    }


    return 0;
}
