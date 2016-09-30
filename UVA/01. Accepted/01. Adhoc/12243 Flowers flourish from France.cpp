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

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

bool CheckString(string s, char c)
{
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1]==' '&&s[i]!=c) return false;
    }
    return true;

}

int main()
{
    char c;
    string s;
    while(getline(cin, s))
    {
        if(s=="*") break;
        for(int i=0;i<s.size();i++)
            s[i]=tolower(s[i]);
        c=s[0];
        if(CheckString(s,c))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;

    }

    return 0;
}


