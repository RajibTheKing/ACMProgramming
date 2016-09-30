#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
#define INF 1<<30
int dp[1100][1100];
string a, b;

int rec(int i, int j)
{
    //cout<<i<<", "<<j<<endl;
    if(i>=a.size()) return 30*(b.size()-j);
    if(j>=b.size()) return 15*(a.size()-i);

    int &ret = dp[i][j];
    int p, q;
    if(ret!=-1) return ret;
    ret = INF;
    if(a[i]==b[j])
        ret = min(ret, rec(i+1, j+1));
    else
    {

        ret = min(ret, 15+rec(i+1,j));
        ret = min(ret, 30+rec(i,j+1));
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);

    while(cin>>a)
    {
        if(a=="#") break;
        cin>>b;
        memset(dp, -1, sizeof(dp));
        int ans = rec(0,0);
        cout<<ans<<endl;

    }
    return 0;
}
