#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;


queue<char> Q;
char a[2000000], temp;
bool isLetter(char c)
{
    if(c>='a'&&c<='z') return true;
    if(c>='A'&&c<='Z') return true;
    return false;
}
bool isVowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string ans;

    int i=0;

    while(gets(a))
    {
        ans="";
        bool f1=false, r=false;
        int l=strlen(a);
        for(int j=0;j<l;j++)
        {
            if(isLetter(a[j])&&f1==false)
            {
                f1=true;
                if(!isVowel(a[j]))
                {
                    r=true;
                    temp=a[j];
                }
                else
                {
                    Q.push(a[j]);
                }

                continue;
            }
            if(isLetter(a[j])&&f1==true)
            {
                Q.push(a[j]);
                continue;
            }

            if(!isLetter(a[j])&&f1==true)
            {
                while(!Q.empty())
                {
                    char g=Q.front();
                    Q.pop();
                    cout<<g;
                }

                if(r==true)
                    printf("%c", temp);
                printf("ay");
                f1=false;
                r=false;
            }
            printf("%c", a[j]);
        }
        cout<<endl;
    }
    return 0;
}
