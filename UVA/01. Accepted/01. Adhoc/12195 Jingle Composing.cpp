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
#define csprnt printf("Case %d:", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

map<char, int> mp;

vector<string> SplitString(string s, char delimiter)
{
    vector<string> result;
    string token;
    stringstream ss(s);
    while(getline(ss,token,delimiter))
    {
        result.push_back(token);
    }
    return result;
}

void Initialize()
{
    mp.clear();
    mp['W']=64;
    mp['H']=32;
    mp['Q']=16;
    mp['E']=8;
    mp['S']=4;
    mp['T']=2;
    mp['X']=1;

}
int main()
{
    Initialize();
    vector<string> s;
    string str;
    while(getline(cin, str))
    {
        if(str=="*") break;
        s = SplitString(str,'/');
        int kount=0;
        for(int i=0;i<s.size();i++)
        {
            int sum=0;
            for(int j=0;j<s[i].size();j++)
            {
                sum+=mp[s[i][j]];
            }
            if(sum==64) kount++;
        }
        cout<<kount<<endl;
    }
}


