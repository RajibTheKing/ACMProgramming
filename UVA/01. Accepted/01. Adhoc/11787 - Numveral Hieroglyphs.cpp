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


int Hierarchy(char c)
{
    if(c=='B') return 1;
    if(c=='U') return 2;
    if(c=='S') return 3;
    if(c=='P') return 4;
    if(c=='F') return 5;
    if(c=='T') return 6;
    if(c=='M') return 7;


}

int Value(char c)
{
    if(c=='B') return 1;
    if(c=='U') return 10;
    if(c=='S') return 100;
    if(c=='P') return 1000;
    if(c=='F') return 10000;
    if(c=='T') return 100000;
    if(c=='M') return 1000000;
}

bool CheckError(string str)
{
    int cur=Hierarchy(str[0]);
    for(int i=1;i<str.size();i++)
    {
        if(Hierarchy(str[i])>cur) return true;
        if(Hierarchy(str[i])<=cur)
            cur=Hierarchy(str[i]);

    }
    int a[200];
    memset(a, 0, sizeof(a));
    for(int i=0;i<str.size();i++)
    {
        a[str[i]]++;
        if(a[str[i]]>9) return true;
    }
    return false;
}

void PrintAnswer(string str)
{
    int sum=0;
    for(int i=str.size()-1;i>=0;i--)
    {
        sum+=Value(str[i]);
    }
    cout<<sum<<endl;
}
int main()
{
   // freopen("input.txt", "r", stdin);

    int T;
    cin>>T;
    string str;
    while(T--)
    {
        cin>>str;
        if(CheckError(str))
        {
            reverse(str.begin(), str.end());
            if(CheckError(str))
                cout<<"error"<<endl;
            else
                PrintAnswer(str);
        }
        else
        {
            PrintAnswer(str);
        }

    }

    return 0;
}
