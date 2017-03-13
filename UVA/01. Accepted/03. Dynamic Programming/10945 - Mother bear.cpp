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



bool isPalindrome(int i, int j, string str)
{
    if(i>j) return true;
    else if(str[i]!=str[j]) return false;
    else return isPalindrome(i+1, j-1, str);
}
int main()
{
    string s, str;
    while(getline(cin,s))
    {
        if(s=="DONE") break;

        str="";
        for(int i=0;i<s.length();i++)
        {
            s[i] = tolower(s[i]);
            if(s[i]>='a'&&s[i]<='z')
                str+=s[i];
        }

        if(isPalindrome(0, str.length()-1, str))
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");

    }

    return 0;
}

