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
    if(str[i]!=str[j]) return false;
    else
        return isPalindrome(i+1, j-1, str);
}
int Find_ans(string str)
{
    char s[100];
    char c[100];

    long long a, b, sum;
    int k = 0;
    while(isPalindrome(0, str.length()-1, str)==false)
    {
        k++;

        stringstream ss;
        ss.clear();
        ss<<str;
        ss>>s;
        ss.clear();
        ss<<str;
        ss>>a;
        reverse(s, s+strlen(s));
        ss.clear();
        ss<<s;
        ss>>b;
        sum = a+b;
        ss.clear();
        ss<<sum;
        ss>>str;

    }
    cout<<k<<" "<<str<<endl;
    return k;
}

int main()
{
    string str;

    long long N;
    int Test, kase=0, kount;
    scanf("%d", &Test);
    getchar();

    while(Test--)
    {
        cin>>str;
        kount = Find_ans(str);
    }

    return 0;
}

