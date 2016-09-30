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
using namespace std;

#define pi 3.1415926535897932384626433832795

string INF="";

int dp[150][150];
bool flag[150][150];
string Set[150][150];
string a, b;

int LCS(int i, int j)
{
    if(i<0||j<0) return 0;
    int &ret = dp[i][j];

    if(ret!=-1) return ret;

    if(a[i]==b[j])
    {
        ret = 1+ LCS(i-1, j-1);
        return ret;
    }

    ret = max(LCS(i-1, j), LCS(i, j-1));
    return ret;
}


string Path(int i, int j)
{
    if(i<0||j<0) return "";
    string &S = Set[i][j];

    if(flag[i][j]) return S;
    flag[i][j]=true;
    string R;
    S=INF;
    if(a[i]==b[j])
    {
        R = Path(i-1, j-1) + a[i];
        if(R<S) S=R;
    }
    if(LCS(i, j)==LCS(i-1, j))
    {
        R = Path(i-1, j);
        if(R<S) S=R;
    }
    if(LCS(i, j)==LCS(i, j-1))
    {
        R = Path(i, j-1);
        if(R<S) S=R;
    }
    return S;

}
int main()
{
    //freopen("input.txt", "r", stdin);
    for(int i=0;i<=105;i++) INF+="z";
    string Result;

    int T, check;
    cin>>T;
    for(int kase=1; kase<=T; kase++)
    {
        memset(dp, -1, sizeof(dp));
        memset(flag, 0, sizeof(flag));
        cin>>a;
        cin>>b;

        check = LCS(a.length()-1, b.length()-1);
        if(check==0)
            printf("Case %d: :(\n", kase);
        else
        {
            Result = Path(a.length()-1, b.length()-1);
            printf("Case %d: ", kase);
            cout<<Result<<endl;
        }

    }
    return 0;
}


